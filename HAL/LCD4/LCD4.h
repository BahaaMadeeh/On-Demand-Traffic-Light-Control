/*
 * LCD4.h
 *
 * Created: 9/16/2022 2:02:42 AM
 *  Author: Bahaa Madeeh
 */ 


#ifndef LCD4_H_
#define LCD4_H_
//#include "../LCD8/LCD8.h"

void LCD_4_bit_init(void);
void LCD_4_bit_Sendcommand(uint8 Command);
void LCD_4_bit_SendData(uint8 Data);
void LCD_4_bit_Clear(void);
void LCD_4_bit_SendString(uint8 *Ptr);



#endif /* LCD4_H_ */