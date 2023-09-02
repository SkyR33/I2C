
#ifndef		I2C_H
#define		I2C_H

// Inicializar I2C
void I2Cinit();

//	Condicion START del bus I2C
void I2Cstart();

//	Condicion STOP del bus I2C
void I2Cstop();

//	Manda un byte de datos al bus I2C y los guarda en el TWDR
//	setea los bits TWINT y TWEN en el TWCR y aguarda el flag del TWINT que indica que los datos se han transmitido.
void I2Cwrite(unsigned char data);

// Manda un paquete de datos a una direccion i2c especifica
void i2c_send_packet(unsigned char value, unsigned char address);

// Lee el bit que manda el esclavo al maestro indicando que fue exitoso el recibimiento de datos.
unsigned char I2CreadACK();

// Lee el bit que manda el esclaov al maestro indicando que todos los bytes necesarios fueron recibidos, transmision finalizada.
unsigned char I2CreadNACK();

#endif