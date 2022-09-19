/*
 * DIO.h
 *
 * Created: 9/5/2022 5:50:25 PM
 *  Author: Bahaa Madeeh
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/Registers.h"
#include "../../Utilities/BIT_MATHS.h"
//pins defines
//pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//Port defines
#define GROUPA 'A'
#define GROUPB 'B'
#define GROUPC 'C'
#define GROUPD 'D'

//define directions
#define INPUT 0
#define OUTPUT 1

//define values
#define LOW 0
#define HIGH 1

//DIO initialization, write, read, and toggle for pins 
void DIO_init(uint8 PortNo, uint8 PinNo, uint8 Direction);  
void DIO_write(uint8 PortNo, uint8 PinNo, uint8 Value);
void DIO_read(uint8 PortNo, uint8 PinNo, uint8 *value);
void DIO_tog(uint8 PortNo, uint8 PinNo);  //DIO toggle

//DIO Direction, and value for an entire PORT
void DIO_SetGroupDirection(uint8 PortNo , uint8 Direction);
void DIO_SetGroupValue(uint8 PortNo , uint8 Value);



#endif /* DIO_H_ */