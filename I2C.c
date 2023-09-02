       
#include <avr/io.h>
#include "I2C.h"

void I2Cinit()
{
	//set SCL a 400kHz
	TWSR = 0x00;
	TWBR = 0x48;	// 0x48 sacado por el calculo (F_CPU / (2 * TWI_Bit_Rate)) - 8	
}

void I2Cstart()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}

void I2Cstop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void I2Cwrite(unsigned char data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}

unsigned char I2CreadACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while((TWCR&(1<<TWINT))==0);
	return TWDR;
}

unsigned char I2CreadNACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	return TWDR;
}

void i2c_send_packet(unsigned char value, unsigned char address)
{
	I2Cstart();
	I2Cwrite(address);
	I2Cwrite(value);
	I2Cstop();
}