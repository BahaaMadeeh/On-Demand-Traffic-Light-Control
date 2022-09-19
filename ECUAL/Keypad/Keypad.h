/*
 * Keypad.h
 *
 * Created: 9/16/2022 2:18:10 AM
 *  Author: Bahaa Madeeh
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../Utilities/STD_TYPES.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO.h"

/*____________________Macros_________________*/
#define KPD_PORT			GROUPD
#define COLUMN_INIT			0
#define COLUMN_FINAL		4
#define ROW_INIT			4
#define ROW_FINAL			8
#define NOT_PRESSED			0	

/*______________Function__________*/
uint8 KPD_GetPressedKey(void);


#endif /* KEYPAD_H_ */