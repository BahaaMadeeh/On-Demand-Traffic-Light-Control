/*
 * UART.c
 *
 * Created: 9/16/2022 3:11:41 AM
 *  Author: Bahaa Madeeh
 */ 

#include "UART.h"

void UART_init(void)
{
	
	/* Select baud rate 9600 on normal speed (U2X=0) and F_CPU =8 MHZ */
	uint16 baudRate=51; /* From data sheet */
	UBRRH = (uint8)(baudRate>>8); /* high nibble */
	UBRRL = (uint8)baudRate;  /* low nibble */
	
	/* UART enable - transmit and recieve */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	
	/* Set frame format - 8 data bits, no parity, and 1 stop bits */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
	
}
void UART_SendChar(uint8 data)
{
	/* Wait for empty transmit buffer */
	while(!(UCSRA & (1<<UDRE)));
	
	/* Put data into buffer, sends the data */
	UDR=data;
}
uint8 UART_GetChar(void)
{
	uint8 Result =0;
	/* Wait for data to be received */
	while(!(UCSRA & (1<<RXC)));
	
	/* Get received data from buffer */
	Result = UDR;
	
	/* Clear Buffer (flag) */
	SET_BIT(UCSRA,7);
	
}