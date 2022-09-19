/*
 * LCD4.c
 *
 * Created: 9/16/2022 2:03:02 AM
 *  Author: Bahaa Madeeh
 */ 

#include "LCD4.h"

void LCD_4_bit_init(void)
{
	/*  set DDRA as OUTPUTs pins  */
	DIO_SetGroupDirection(GROUPA,0xFF);
	_delay_ms(20);
	LCD_4_bit_Sendcommand(0x02);			/* Send for 4bit initialization of LCD */
	LCD_4_bit_Sendcommand(0X20);			/* 2 line, 5x7 matrix in 4bit mode */
	LCD_4_bit_Sendcommand(0x0C);			/* Display on, cursor off */
	LCD_4_bit_Sendcommand(0x06);			/* Increment cursor (left to right) */
	LCD_4_bit_Sendcommand(0x01);			/* Clear display screen */
}

