#ifndef LIB_SPI4PI_H
#define LIB_SPI4PI_H

#endif // LIB_SPI4PI_H

#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <pigpio.h>

#define SPI_CHANNEL 0 //update just set as 1 as a temp value
#define SPI_BAUD 52000

/*
 * FOR FLAG OPTIOINS: https://abyz.me.uk/rpi/pigpio/python.html#spi_open
 *
 */
#define SPI_FLAGS 3

#define PIN_MOSI 10
#define PIN_MISO 9
#define PIN_SCLK 11
#define PIN_SS 8
class spi4pi {
public:
    spi4pi();
    ~spi4pi();

    int send_message(char *message);
private:
    int spi_handle;
};
