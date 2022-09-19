/*
 * timer.c
 *
 * Created: 9/6/2022 12:11:36 AM
 *  Author: Bahaa Madeeh
 */ 
#include "timer.h"
#include <math.h>
#include "../../Utilities/BIT_MATHS.h"

void Timer0_init()
{
	//normal mode
	TCCR0_REG=0x00;
	
}

void Timer0_delay(uint16 delay_ms)
{
	//using 256 prescalar, 1Mhz Fcpu with normal mode
	double tickTime, MaxDelayTime;
	uint16 NoOF, initialTime; 
	int OVFcount=0;  //NoOF -> number of overflow
	tickTime=256.0/1000.0;
	MaxDelayTime = 65.536; //tickTime*(2^8);
	
	//calculate maximum delay
	if (delay_ms < MaxDelayTime)   //set initial value for timer and wait 1 Overflow
	{
		initialTime=(MaxDelayTime-delay_ms)/tickTime;
		NoOF = 1;  //number of overflow
	}else if(delay_ms == (uint32)MaxDelayTime)////set initial value = 0 for timer and wait 1 Overflow
	{
		initialTime=0;
		NoOF=1;
	}else           //calculate no. of needed overflows, and set initial value for timer
	{
		NoOF=ceil((double)delay_ms/MaxDelayTime);
		initialTime=(1<<8)-(((double)delay_ms/tickTime)/NoOF); //256.0
	}
	//
	TCNT0_REG= initialTime;
	TCCR0_REG |= (1<<2);  //SET prescalar at 256
	
	while(OVFcount < NoOF)
	{
		while(GET_BIT(TIFR_REG,0) == 0);   //WAIT 'TILL FLAG IS SET
		SET_BIT(TIFR_REG,0);   //clear overflow flag
		OVFcount++;
	}
	//stop timer
	TCCR0_REG = 0x00;
	
	
}