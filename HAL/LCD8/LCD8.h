/*
 * LCD8.h
 *
 * Created: 9/16/2022 1:27:53 AM
 *  Author: Bahaa Madeeh
 */ 


#ifndef LCD8_H_
#define LCD8_H_

#include "../../Utilities/STD_TYPES.h"

/*__________________Macros________________*/
#define LCD_GROUP_DATA			GROUPA
#define LCD_GROUP_CONTROL		GROUPB
#define LCD_RS_PIN				PIN0
#define LCD_E_PIN				PIN1
#define LCD_HOME				0x02			/* Return cursor to the first position on the first line*/
#define LCD_SET_8FUNCTION		0x38			/* 8_bit data, 2-line display, 5x7 font */
#define LCD_CLEAR				0x01			/* Replace all chars with ASCII space */
#define LCD_DATA_ENTRY			0x06			/* Shift cursor from left to right on read/write */
#define LCD_DISPLAY_ON			0x0C			/* Display on, cursor off, no blink character */
#define LCD_DISPLAY_OFF			0x08			/* Turn display off */
#define LCD_FUNCTION_RESET		0x30			/* Reset LCD */
#define LCD_SET_CURSOR			0x80			/* Set cursor Position */

/*__________________Functions_______________*/
void LCD_8_bit_init(void);
void LCD_8_bit_SendCommand(uint8 command);
void LCD_8_bit_SendData(uint8 data);
void LCD_8_bit_Clear(void);
void LCD_8_bit_SendString(uint8 *ptr);



#endif /* LCD8_H_ */