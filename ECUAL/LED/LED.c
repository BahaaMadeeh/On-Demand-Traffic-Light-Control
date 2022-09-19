/*
 * LED.c
 *
 * Created: 9/5/2022 6:13:49 PM
 *  Author: Bahaa Madeeh
 */ 
#include "LED.h"
#include <avr/delay.h>
void LED_init(uint8 LedPort,uint8 LedPin)
{
	DIO_init(LedPort,LedPin,OUTPUT);
}

void LED_on(uint8 LedPort,uint8 LedPin)
{
	DIO_write(LedPort,LedPin,HIGH);
}

void LED_off(uint8 LedPort,uint8 LedPin)
{
	DIO_write(LedPort,LedPin,LOW);
}

void LED_tog(uint8 LedPort,uint8 LedPin)
{
	DIO_tog(LedPort,LedPin);
}

void LED_CAR_YELLOW_BLINK(uint8 LedPort, uint8 LedPin)
{

	LED_on(LedPort, LedPin);

	_delay_ms(500);
	LED_off(LedPort, LedPin);
	_delay_ms(500);
	LED_on(LedPort, LedPin);
	_delay_ms(500);
	LED_off(LedPort, LedPin);
	_delay_ms(500);
	LED_on(LedPort, LedPin);
	_delay_ms(500);
	LED_off(LedPort, LedPin);
	_delay_ms(500);
	LED_on(LedPort, LedPin);
	_delay_ms(500);
	LED_off(LedPort, LedPin);
	_delay_ms(500);
	LED_on(LedPort, LedPin);
	_delay_ms(500);
}
void LED_PED_YELLOW_BLINK(uint8 LedPort, uint8 LedPin)
{
	LED_on(LedPort, LedPin);

	delay(500);
	LED_off(LedPort, LedPin);
	delay(500);
	LED_on(LedPort, LedPin);
	delay(500);
	LED_off(LedPort, LedPin);
	delay(500);
	LED_on(LedPort, LedPin);
	delay(500);
	LED_off(LedPort, LedPin);
	delay(500);
	LED_on(LedPort, LedPin);
	delay(500);
	LED_off(LedPort, LedPin);
	delay(500);
	LED_on(LedPort, LedPin);
	delay(500);
}