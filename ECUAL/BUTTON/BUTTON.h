/*
 * BUTTON.h
 *
 * Created: 9/5/2022 6:48:31 PM
 *  Author: Bahaa Madeeh
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"

//macros for button port and pin
#define BUTTON_PORT GROUPD
#define BUTTON_PIN PIN2

void BUTTON_init(uint8 ButtonPort, uint8 ButtonPin);
void BUTTON_read(uint8 ButtonPort, uint8 ButtonPin, uint8 *value);


#endif /* BUTTON_H_ */