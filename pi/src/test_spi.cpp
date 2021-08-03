#include "../include/lib_spi4pi.h"

#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    unsigned char to_send[4] = {0x1A, 0xA1, 0x1A, 0xA1};
    spi4pi pi;

    pi.send_message((char*)to_send);
}
