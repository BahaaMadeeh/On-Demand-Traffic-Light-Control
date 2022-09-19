/*
 * SPI.c
 *
 * Created: 9/16/2022 5:42:04 AM
 *  Author: Bahaa Madeeh
 */ 
#include "SPI.h"

uint8 flushBuffer;
void SPI_init(void)
{
	DIO_SetGroupDirection(GROUPA, OUTPUT);
	/* Set MOSI, SCK, SS as an output pins */
	DIO_init(SPI_PORT, MOSI, OUTPUT);
	DIO_init(SPI_PORT, SCK, OUTPUT);
	DIO_init(SPI_PORT, SS, OUTPUT);
	
	/* Set MISO pin as an input pin */
	DIO_init(SPI_PORT, MISO, INPUT);
	
	/* Set SS Pin to high */
	DIO_write(SPI_PORT, SS, HIGH);
	
	/* Enable SPI in master mode with 16 prescalar */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
	/* Disable speed doubler */
	CLEAR_BIT(SPSR,SPI2X);
}
void SPI_SendCommand(uint8 command)
{
	
	#if 1
	/* Pull SS pin to low */
	DIO_write(SPI_PORT, SS, LOW);
	
	/* Write data to SPI data register */
	SPDR = command;
	
	/* Wait till transmission complete */
	while(!(SPSR & (1<<SPIF)));
	
	/* Flush received data */
	flushBuffer = SPDR;
	
	/* Set SS pin to high */
	DIO_write(SPI_PORT, SS, HIGH);
	#endif
}
uint8 SPI_Recieve(void)
{
	#if 0
	
	/* Set dummy value */
	SPDR = 0xFF;
	
	/* wait till reception complete */
	while (!(SPSR & (1<<SPIF)));
	
	/* Return received data */
	flushBuffer = SPDR;
	
	GROUPA = flushBuffer;
	#endif	
}