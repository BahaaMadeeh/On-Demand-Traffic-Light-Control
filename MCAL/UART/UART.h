/*
 * UART.h
 *
 * Created: 9/16/2022 3:11:34 AM
 *  Author: Bahaa Madeeh
 */ 


#ifndef UART_H_
#define UART_H_
#include "../../Utilities/BIT_MATHS.h"
#include "../../Utilities/STD_TYPES.h"

void UART_init(void);
void UART_SendChar(uint8 data);
uint8 UART_GetChar(void);



#endif /* UART_H_ */