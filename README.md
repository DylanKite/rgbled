# Addressable RGB LED project

This project is to learn how to control An RGB LED strip from a google home using a Raspberry pi 3b as the server

## Project Materials
- Google Home
- Raspberry Pi 3b
- LED Strip: WS2812B
  - 5V
  - 9A?
  - 45W?

## Protocals
### LED Strip:
- PWM

### Google Home To Pi
- Web server?

##File Descriptions
###lib_nanosec
- Lib_nanosec is based off of the program written by user dranger003 called nanopulse.c
- the above program is being modified into a c++ library that can be used multiple times
  and will be the basis for the protocol used to communicate with the LED Strip.
