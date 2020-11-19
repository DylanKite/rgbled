#include "../include/lib_nanopulse.h"
#include "../include/nano_defs.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    int gpio;
    int mode;
    int nanos = 1000;
    int pulses = 100;
    int gap = 5000;

    pwm_clock_cfg_t cfg;
    nano_pulse nano;

    if (argc > 1) {
        nanos = atoi(argv[1]);
    }
    if (argc > 2) {
        pulses = atoi(argv[2]);
    }
    if (argc > 3) {
        gap = atoi(argv[3]);
    }
    if (nanos < 4) {
        nanos = 4;
    } else if (nanos > 224000) {
        nanos = 224000;
    }
    if (pulses < 1) {
        pulses = 1;
    }
    if (gap < 0) {
        gap = 0;
    }

    cfg = nano.getDivBits(nanos);

    printf("%d pulses of %d nanos with gap of %d nanos (div=%d bits=%d)\n",
           pulses, cfg.divider * 2 * cfg.bits, gap, cfg.divider, cfg.bits);


    initPWM(cfg.divider);

    for (i = 0; i < pulses; i++) {
        sendPulse(cfg.bits);

        mynanosleep(nanos + gap);
    }


}
