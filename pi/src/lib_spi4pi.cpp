#include "../include/lib_spi4pi.h"

#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>

using namespace std;

spi4pi::spi4pi()
{
    //set gpio mode
    // initialize connection
    gpioInitialise();
    gpioSetMode(PIN_SCLK, PI_OUTPUT);
    gpioSetMode(PIN_MOSI, PI_OUTPUT);
    gpioSetMode(PIN_SS, PI_OUTPUT);
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
    return 0;
}
