#include <cstdint>

class message {


    public:
        message();
        ~message();

        int8_t send_message();
        int8_t test_pwm_usec(uint16_t pulse_width_usec, uint8_t n_pulses);
    private:
        int8_t init_pins(uint8_t selected_pin, uint8_t pin_mode);
};
