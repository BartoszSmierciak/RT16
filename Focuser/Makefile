#compiler name
CC := gcc 

CFLAGS := -Wall `pkg-config --cflags --libs libmodbus` -lmodbus

#remove command
RM := rm -rf

#source files
SOURCES := Focuser/main.cpp Focuser/IG5A.cpp

#object files
OBJS := $(SOURCES:.c=.o)

#main target
main: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) *.o main