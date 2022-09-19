/*
 * LED.h
 *
 * Created: 9/5/2022 6:13:42 PM
 *  Author: Bahaa Madeeh
 */ 

#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"

//car and PED ports macros
#define LED_CAR_PORT GROUPA
#define LED_PED_PORT GROUPB

//car led pins macros
#define LED_CAR_GREEN_PIN PIN0
#define LED_CAR_YELLOW_PIN PIN1
#define LED_CAR_RED_PIN PIN2

//PED led pins macros
#define LED_PED_GREEN_PIN PIN0
#define LED_PED_YELLOW_PIN PIN1
#define LED_PED_RED_PIN PIN2

void LED_init(uint8 LedPort,uint8 LedPin);
void LED_on(uint8 LedPort,uint8 LedPin);
void LED_off(uint8 LedPort,uint8 LedPin);
void LED_tog(uint8 LedPort,uint8 LedPin);

void LED_CAR_YELLOW_BLINK(uint8 LedPort, uint8 LedPin);
void LED_PED_YELLOW_BLINK(uint8 LedPort, uint8 LedPin);



#endif /* LED_H_ */