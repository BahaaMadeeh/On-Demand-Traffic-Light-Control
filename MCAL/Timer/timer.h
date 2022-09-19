/*
 * timer.h
 *
 * Created: 9/6/2022 12:11:27 AM
 *  Author: Bahaa Madeeh
 */ 




#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/Registers.h"
#include "../../Utilities/BIT_MATHS.h"


void Timer0_init();
void Timer0_delay(uint16 delay_ms);  //time delay with 256 prescalar as default


#endif /* TIMER_H_ */