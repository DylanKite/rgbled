/*
   Compile and link

   gcc -o nanopulse nanopulse.c

   Run example (10000 10 nanosecond pulses with 2000 nano second gap)

   sudo ./nanopulse 10 10000 2000
 */

#include "../include/lib_nanopulse.h"
#include "../include/nano_defs.h"

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include <iostream>

using namespace std;

unsigned base_nano[] = {4, 8, 10, 20, 40, 80, 100, 200, 250, 500, 1000};

void nano_pulse::mynanosleep(unsigned nanos) {
    struct timespec ts; // requested
    struct timespec tr; // remaining

    ts.tv_sec = 0;
    ts.tv_nsec = nanos;
    while (nanosleep(&ts, &tr)) {
        ts = tr;
    }
}

int nano_pulse::gpioSetMode(unsigned gpio, unsigned mode) {
    int reg, shift;

    reg = gpio / 10;
    shift = (gpio % 10) * 3;

    gpioReg[reg] = (gpioReg[reg] & ~(7 << shift)) | (mode << shift);

    return 0;
}

int nano_pulse::gpioGetMode(unsigned gpio) {
    int reg, shift;

    reg = gpio / 10;
    shift = (gpio % 10) * 3;

    return (*(gpioReg + reg) >> shift) & 7;
}

void nano_pulse::initPWM(unsigned divider) {
    /* reset PWM clock */
    clkReg[CLK_PWMCTL] = CLK_PASSWD | CLK_CTL_KILL;

    mynanosleep(10000);

    /* set PWM clock source as 500 MHz PLLD */
    clkReg[CLK_PWMCTL] = CLK_PASSWD | CLK_CTL_SRC(CLK_CTL_SRC_PLLD);

    mynanosleep(10000);

    /* set PWM clock divider */
    clkReg[CLK_PWMDIV] = CLK_PASSWD | CLK_DIV_DIVI(divider) | CLK_DIV_DIVF(0);

    mynanosleep(10000);

    /* enable PWM clock */
    clkReg[CLK_PWMCTL] =
        CLK_PASSWD | CLK_CTL_ENAB | CLK_CTL_SRC(CLK_CTL_SRC_PLLD);

    mynanosleep(100000);

    /* reset PWM */
    pwmReg[PWM_CTL] = 0;

    /* clear PWM status bits */
    pwmReg[PWM_STA] = -1;

    mynanosleep(10000);
}

void nano_pulse::sendPulse(unsigned bits) {
    uint32_t word;

    if (bits == 0)
        bits = 1;
    else if (bits > MAX_BITS)
        bits = MAX_BITS;

    /* clear PWM fifo */

    pwmReg[PWM_CTL] = PWM_CTL_CLRF1;

    //mynanosleep(10000);

    while (bits >= 32) {
        pwmReg[PWM_FIFO] = -1;
        bits -= 32;
    }

    if (bits) {
        word = 0;

        for (unsigned int i = 0; i < bits; i++)
        {
            word |= (1 << (31 - i));
        }
        pwmReg[PWM_FIFO] = word;
    }

    pwmReg[PWM_FIFO] = 0;

    /* enable PWM for serialised data from fifo */
    pwmReg[PWM_CTL] = PWM_CTL_USEF1 | PWM_CTL_MODE1 | PWM_CTL_PWEN1;
}

uint32_t *nano_pulse::mapMem(int fd, unsigned base, unsigned len) {
    uint32_t *rtn_map;
    rtn_map = (uint32_t*)mmap(0, len, PROT_READ | PROT_WRITE | PROT_EXEC,
                               MAP_SHARED | MAP_LOCKED, fd, base);
    return rtn_map;
}

pwm_clock_cfg_t nano_pulse::getDivBits(unsigned nano) {
    pwm_clock_cfg_t cfg;

    unsigned bits;
    unsigned err;
    unsigned bestErr = -1;
    unsigned bestBase;
    unsigned bestBits;

    for (unsigned i = 0; i < sizeof(base_nano) / sizeof(unsigned); i++) {
        bits = nano / base_nano[i];

        if (bits > MAX_BITS)
            bits = MAX_BITS;

        err = nano - (bits * base_nano[i]);

        if (err < bestErr) {
            bestErr = err;
            bestBase = base_nano[i];
            bestBits = bits;
        }
    }

    cfg.divider = bestBase / 2;
    cfg.bits = bestBits;

    return cfg;
}

void nano_pulse::cfg_protocol_clock()
{
    high_0 = getDivBits(350);
    low_0 = getDivBits(900);
    high_1 = getDivBits(900);
    low_1 = getDivBits(350);
}

nano_pulse::nano_pulse() {
    int fd_mem;

    fd_mem = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd_mem < 0) {
        printf("need to run as root, e.g. sudo\n");
        exit(1);
    }

    clkReg = (uint32_t*)MAP_FAILED;
    gpioReg = (uint32_t*) MAP_FAILED;
    pwmReg = (uint32_t*)MAP_FAILED;

    gpioReg = mapMem(fd_mem, GPIO_BASE, GPIO_LEN);
    pwmReg = mapMem(fd_mem, PWM_BASE, PWM_LEN);
    clkReg = mapMem(fd_mem, CLK_BASE, CLK_LEN);

    close(fd_mem);

    /* save original mode */
    origin_pin_mode = gpioGetMode(OUTPUT_PIN);
    gpioSetMode(OUTPUT_PIN, 2); /* set to ALT5, PWM1 */
}

nano_pulse::~nano_pulse() {
    /* restore original mode */
    gpioSetMode(OUTPUT_PIN, origin_pin_mode);
}
