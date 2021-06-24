#include "IG5A.h"
#include <stdio.h>

#define INVERTER 1

int main()
{
    IG5A Inverter;
    Inverter.ModbusInit("/dev/ttyUSB0", 9600, 'N', 8, 1);
	printf("inventer: %u\n", Inverter.ModbusRead(1, 0xA215));
	
	Inverter.ModbusClose();
    return 0;
}