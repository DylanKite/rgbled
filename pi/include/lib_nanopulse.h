#include <cstdint>
class nano_pulse
{
public:
    int gpioSetMode(unsigned gpio, unsigned mode);
    int gpioGetMode(unsigned gpio);
    static void sendPulse(unsigned bits);
    typedef struct
    {
       unsigned divider;
       unsigned bits;
    } pwm_clock_cfg_t;

private:
    static void initPWM(unsigned divider);
    static uint32_t * mapMem(int fd, unsigned base, unsigned len);
    pwm_clock_cfg_t getDivBits(unsigned nano);
};
