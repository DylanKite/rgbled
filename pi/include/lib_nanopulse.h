#include "nano_defs.h"

#include <sys/mman.h>
#include <cstdint>

class nano_pulse {
public:
nano_pulse();
~nano_pulse();

int gpioSetMode(unsigned gpio, unsigned mode);
int gpioGetMode(unsigned gpio);

void sendPulse(unsigned bits);
void initPWM(unsigned divider);
void mynanosleep(unsigned nanos);

pwm_clock_cfg_t getDivBits(unsigned nano);

private:
volatile uint32_t *clkReg = (uint32_t *)MAP_FAILED;
volatile uint32_t *gpioReg = (uint32_t *)MAP_FAILED;
volatile uint32_t *pwmReg = (uint32_t *)MAP_FAILED;

int origin_pin_mode;

pwm_clock_cfg_t high_0;
pwm_clock_cfg_t low_0;
pwm_clock_cfg_t high_1;
pwm_clock_cfg_t low_1;

uint32_t *mapMem(int fd, unsigned base, unsigned len);
void cfg_protocol_clock();
};
