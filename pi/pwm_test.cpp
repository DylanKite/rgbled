#include "pwm_test.h"


#include <wiringPi.h>

#include <cstdint>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#define SELECTED_PIN 12

using namespace std;
message::message()
{
    wiringPiSetup();
    pinMode(SELECTED_PIN, PWM_OUTPUT);
}

message::~message()
{

}

/*
int8_t message::init_pins(uint8_t selected_pin, uint8_t pin_mode)
{

}
*/
int8_t message::test_pwm_usec(uint16_t pulse_width_usec, uint8_t n_pulses)
{
 return 0;
}

int main(int argc, char* argv[])
{
    if (argc > 1 )
    {
        for(int i = 0; i < argc; i++)
        {
            cout << argv[i] << "\n";
        }
    }
    return 0;
}
