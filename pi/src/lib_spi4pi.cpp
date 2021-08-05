#include "../include/lib_spi4pi.h"

#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>
#include <iostream>

using namespace std;

spi4pi::spi4pi()
{
    //set gpio mode
    // initialize connection
    gpioInitialise();
    gpioSetMode(PIN_SCLK, PI_ALT0);
    gpioSetMode(PIN_MOSI, PI_ALT0);
    gpioSetMode(PIN_MISO, PI_ALT0);
    gpioSetMode(PIN_SS, PI_ALT0);
    spi_handle = spiOpen(SPI_CHANNEL, SPI_BAUD, SPI_FLAGS);
}
spi4pi::~spi4pi()
{
    //close connection
    spiClose(spi_handle);
    gpioTerminate();
}
int spi4pi::send_message(char *buffer)
{
    spiWrite(spi_handle, buffer, 4);
    cout << "writing spi";
    return 0;
}
