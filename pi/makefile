CC=g++
CFLAGS=-I -Wall 
INC=./include/
SRC=./src/

%.o: %.c $(DEPS)
nano_test: test_nano.o lib_nanopulse.o
	$(CC) test_nano.o lib_nanopulse.o $(CFLAGS)

lib_nanopulse.o: $(SRC)lib_nanopulse.cpp $(INC)lib_nanopulse.h
	$(CC) -c $(SRC)lib_nanopulse.cpp $(CFLAGS)

test_nano.o: $(SRC)test_nano.cpp
	$(CC) -c $(SRC)test_nano.cpp $(CFLAGS)
