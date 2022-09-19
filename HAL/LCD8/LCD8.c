/*
 * LCD.c
 *
 * Created: 9/16/2022 1:23:47 AM
 *  Author: Bahaa Madeeh
 */ 
#include "LCD8.h"
#include "../../MCAL/DIO/DIO.h"
#include "avr/delay.h"

void LCD_8_bit_init(void)
{
	  /*  set DDRA as OUTPUTs pins  */
	  DIO_SetGroupDirection(LCD_GROUP_DATA,0xFF);
	  /*  configure RS & E as OUTPUT  */
	  DIO_SetGroupDirection(LCD_GROUP_CONTROL,LCD_RS_PIN,OUTPUT);
	  DIO_SetGroupDirection(LCD_GROUP_CONTROL,LCD_E_PIN,OUTPUT);
	  _delay_ms(20);
	  LCD_8_bit_SendCommand(LCD_HOME);
	  _delay_ms(15);
	  LCD_8_bit_SendCommand(LCD_SET_8FUNCTION);
	  _delay_ms(1);
	  LCD_8_bit_SendCommand(LCD_DISPLAY_ON);
	  _delay_ms(1);
	  LCD_8_bit_SendCommand(LCD_CLEAR);
	  _delay_ms(2);
	  LCD_8_bit_SendCommand(LCD_DATA_ENTRY);
	  _delay_ms(15);
	  
}

void LCD_8_bit_SendCommand(uint8 command)
{
	DIO_write(LCD_GROUP_CONTROL,LCD_RS_PIN,LOW);
	_delay_us(1);
	DIO_write(LCD_GROUP_CONTROL,LCD_E_PIN,HIGH);
	_delay_us(1);
	DIO_SetGroupValue(LCD_GROUP_DATA,command);
	_delay_us(1);
	DIO_write(LCD_GROUP_CONTROL,LCD_E_PIN,LOW);
	_delay_us(5);
	DIO_write(LCD_GROUP_CONTROL,LCD_E_PIN,HIGH);
	_delay_ms(10);
}

void LCD_8_bit_SendData(uint8 data)
{
		DIO_write(LCD_GROUP_CONTROL,LCD_RS_PIN,LOW);
		_delay_us(1);
		DIO_write(LCD_GROUP_CONTROL,LCD_E_PIN,HIGH);
		_delay_us(1);
		DIO_SetGroupValue(LCD_GROUP_DATA,data);
		_delay_us(1);
		DIO_write(LCD_GROUP_CONTROL,LCD_E_PIN,LOW);
		_delay_us(5);
		DIO_write(LCD_GROUP_CONTROL,LCD_E_PIN,HIGH);
		_delay_ms(10);
}

void LCD_8_bit_SendString(uint8 *ptr)
{
	uint8 index=0;
	while(ptr[index] != '\0')
	{
		LCD_8_bit_SendData(ptr[index]);
		index++;
	}
}

void LCD_8_bit_Clear(void)
{
	LCD_8_bit_SendCommand(LCD_CLEAR);
}