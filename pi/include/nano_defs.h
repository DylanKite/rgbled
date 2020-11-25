#ifndef NANO_DEFS_H
#define NANO_DEFS_H

#define BCM2708_PERI_BASE 0x3F000000
#define CLK_ADDR 0x101000
#define GPIO_ADDR 0x200000
#define PWM_ADDR 0x20C000

#define CLK_BASE BCM2708_PERI_BASE + CLK_ADDR
#define GPIO_BASE BCM2708_PERI_BASE + GPIO_ADDR
#define PWM_BASE BCM2708_PERI_BASE + PWM_ADDR

#define CLK_LEN 0xA8
#define GPIO_LEN 0xB4
#define PWM_LEN 0x28

#define PWM_CTL 0
#define PWM_STA 1
#define PWM_RNG1 4
#define PWM_FIFO 6

#define PWM_CTL_CLRF1 (1 << 6)
#define PWM_CTL_USEF1 (1 << 5)
#define PWM_CTL_MODE1 (1 << 1)
#define PWM_CTL_PWEN1 (1 << 0)

#define PWM_STA_EMPT1 (1 << 1)

#define CLK_PASSWD (0x5A << 24)

#define CLK_CTL_MASH(x) ((x) << 9)
#define CLK_CTL_BUSY (1 << 7)
#define CLK_CTL_KILL (1 << 5)
#define CLK_CTL_ENAB (1 << 4)
#define CLK_CTL_SRC(x) ((x) << 0)

#define CLK_CTL_SRC_PLLD 6 /* 500.0 MHz */

#define CLK_DIV_DIVI(x) ((x) << 12)
#define CLK_DIV_DIVF(x) ((x) << 0)

#define CLK_PWMCTL 40
#define CLK_PWMDIV 41

#define MAX_BITS 224

#define OUTPUT_PIN 18

typedef struct {
    unsigned divider;
    unsigned bits;
} pwm_clock_cfg_t;

#endif // NANO_DEFS_H
