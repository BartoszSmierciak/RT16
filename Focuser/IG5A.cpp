#include <modbus/modbus.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "IG5A.h"

IG5A::IG5A()
{
//constructor    
}

int IG5A::GetFrequencyCommand()
{
    return _frequencyCommand;
}
    
void IG5A::SetFrequencyCommand(int frequencyCommand)
{
    if(frequencyCommand >=0 && frequencyCommand<=400 )
        _frequencyCommand = frequencyCommand;
    else
        _frequencyCommand = 0;
        
}

int IG5A::ModbusInit(const char *device, int baud, char parity, int data_bit, int stop_bit)
{

    uint32_t tv_sec  = 0;
    uint32_t tv_usec = 0;

    uint32_t resTimeSec = 0;
    uint32_t resTimeuSec = 600000;

    //printf("\n");
    //printf("Trying to connect...");
    ctx = modbus_new_rtu(device, baud, parity, data_bit, stop_bit);
    if (modbus_connect(ctx) == -1)
    {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_close(ctx);
        modbus_free(ctx);
        return -1;
    }
    if (NULL == ctx)
    {
        printf("Unable to create modbus context\n");
        modbus_close(ctx);
        modbus_free(ctx);
        return -1;
    }
    //printf("OK.\nCreated modbus context\n");
    /* Get response timeout */
    modbus_get_response_timeout(ctx, &tv_sec, &tv_usec); 
    //printf("Default response timeout: %d sec %d usec \n", tv_sec, tv_usec );

    /* Set response timeout */
    modbus_set_response_timeout(ctx, resTimeSec, resTimeuSec); 
    modbus_get_response_timeout(ctx, &tv_sec, &tv_usec); 
    //printf("Set response timeout:     %d sec %d usec \n", tv_sec, tv_usec );
    return 0;
}

uint16_t IG5A::ModbusRead(int slaveAddress, int regAddress)
{
    //Set the Modbus address of the remote slave
    int rc = modbus_set_slave(ctx, slaveAddress);
    if (rc == -1) 
    {
        fprintf(stderr, "Invalid slave ID: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }

	// will store read register value
    uint16_t reg;

    int num = modbus_read_registers(ctx, regAddress, 1, &reg);
    if (num != 1)
    {
        fprintf(stderr, "Failed to read modbus. Num: %d, error: %s\n", num, modbus_strerror(errno));
    }
    return reg;
}

int IG5A::ModbusWrite(int slaveAddress, int regAddress, uint16_t value)
{

	modbus_set_slave(ctx, slaveAddress);
    int modbusAnswear = modbus_write_register(ctx, regAddress, value);
    if (modbusAnswear != 1)
   {
        printf("ERROR modbus_write_register (%d)\n", modbusAnswear);
        printf("Address = %d, value = %d (0x%X)\n", regAddress, value, value);
    }
    return modbusAnswear;
}

void IG5A::ModbusClose(void)
{
    modbus_close(ctx);
    modbus_free(ctx);
}