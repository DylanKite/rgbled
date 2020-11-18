#include "pwm_test.h"


#include <wiringPi.h>

#include <cstdint>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#define SELECTED_PIN 1 // this is physical pin 12 on the board and gpio pin 18
#define N_PULSES 100
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
    pwmWrite(SELECTED_PIN, pulse_width_usec); 
    cout << "outputting PWM";
    return 0;
}

int main(int argc, char* argv[])
{
    uint16_t freq_usec;
/*    if (argc > 1 )
    {
        for(int i = 0; i < argc; i++)
        {
            cout << "\n" << argv[i] << "\n i val: " << i << "\n";
        }
    }
    else
    {
        cout << argc << "argc val";
    }
*/
    if (argc == 2)
    {
        freq_usec = atoi(argv[1]);
        cout << "freq usec selected: " << freq_usec << "\n";
    }
    else
    {
        cout << "please enter the pwm frequency\n argc = " << argc << "\n";
        return -1;
    }
    
    message pwm;
    pwm.test_pwm_usec(freq_usec, N_PULSES);
    return 0;
}
