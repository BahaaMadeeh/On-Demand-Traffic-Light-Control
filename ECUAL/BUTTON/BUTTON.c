/*
 * BUTTON.c
 *
 * Created: 9/5/2022 6:48:42 PM
 *  Author: Bahaa Madeeh
 */
#include "BUTTON.h"

void BUTTON_init(uint8 ButtonPort, uint8 ButtonPin)
{
	DIO_init(ButtonPort,ButtonPin,OUTPUT);
}

void BUTTON_read(uint8 ButtonPort, uint8 ButtonPin, uint8 *value)
{
	DIO_read(ButtonPort,ButtonPin,value);

}
