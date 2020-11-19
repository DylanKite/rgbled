#include <cstdint>
#include <include/nano_defs.h>

class nano_pulse {
public:
nano_pulse();
~nano_pulse();

int gpioSetMode(unsigned gpio, unsigned mode);
int gpioGetMode(unsigned gpio);

static void sendPulse(unsigned bits);

static volatile uint32_t *clkReg = MAP_FAILED;
static volatile uint32_t *gpioReg = MAP_FAILED;
static volatile uint32_t *pwmReg = MAP_FAILED;
pwm_clock_cfg_t getDivBits(unsigned nano);

private:
int origin_pin_mode;
pwm_clock_cfg_t high_0;
pwm_clock_cfg_t low_0;
pwm_clock_cfg_t high_1;
pwm_clock_cfg_t low_1;
static void initPWM(unsigned divider);
static uint32_t *mapMem(int fd, unsigned base, unsigned len);
static void mynanosleep(unsigned nanos);
void cfg_protocol_clock();
};
