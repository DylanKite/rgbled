CC=g++
CFLAGS=-I -Wall #-lwirigPi
DEPS= -lwiringPi -lpthread -lcrypt -lrt

%.o: %.c $(DEPS)
pwm_test: pwm_test.o
	$(CC) -o pwm_test pwm_test.o $(CFLAGS) $(DEPS)
