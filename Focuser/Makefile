CC = gcc

CFLAGSS  = -g -Wall `pkg-config --cflags --libs libmodbus`

CFLAGSE  = -lmodbus

default: all

all: main.o encoder.o encoderRegisters.o
	$(CC) $(CFLAGSS) main.o IG5A.o -o main $(CFLAGSE)

main.o: main.cpp IG5A.h
	$(CC) $(CFALGSS) -c main.c $(CFLAGSE)

IG5A.o: IG5A.cpp IG5A.h
	$(CC) $(CFLAGSS) -c IG5A.cpp $(CFLAGSE)

clean:
	$(RM) all *.o *~
