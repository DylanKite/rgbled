CC=g++
CFLAGS=-I -Wall 
INC=./include/
SRC=./src/
LIBS=-lpigpio -lrt -pthread 
LIB_PATH= -L/usr/local/include
%.o: %.c $(DEPS)
#nano_test: test_nano.o lib_nanopulse.o
#	$(CC) test_nano.o lib_nanopulse.o $(CFLAGS)

#lib_nanopulse.o: $(SRC)lib_nanopulse.cpp $(INC)lib_nanopulse.h
#	$(CC) -c $(SRC)lib_nanopulse.cpp $(CFLAGS)

#test_nano.o: $(SRC)test_nano.cpp
#	$(CC) -c $(SRC)test_nano.cpp $(CFLAGS)


spi_test: test_spi.o lib_spi4pi.o
	$(CC) $(CFLAGS) test_spi.o lib_spi4pi.o $(LIB_PATH) $(LIBS)

lib_spi4pi.o: $(SRC)lib_spi4pi.cpp $(INC)lib_spi4pi.h
	$(CC) $(CFLAGS) -c $(SRC)lib_spi4pi.cpp $(LIB_PATH) $(LIBS)

test_spi.o:  $(SRC)test_spi.cpp
	$(CC) $(CFLAGS) -c $(SRC)test_spi.cpp #$(LIBS)


