/*
 * Interrupts.h
 *
 * Created: 9/6/2022 4:17:05 PM
 *  Author: Bahaa Madeeh
 */ 

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "Registers.h"


//interrupt vector
#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2

//enable OVF Interrupt Timer 0
#define OVF_INT_TIMER0() TIMSK_REG |=(1<<TOIE0)
//enable GLOBAL interrupt
//#define EnableGI() (SREG_REG |=(1<<7))
//#define DisableGI() (SREG_REG&=~(1<<7))
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

//choosing SENSE rising edge
#define RISING_EDGE_SETUP() MCUCR_REG|=(1<<0)|(1<<1)

//ENABLE EXTERNAL INTERRUPE INT0
#define SETUP_INT0() GICR_REG|=(1<<6)

//ISR macros
#define ISR(INT_VECT) \
	void INT_VECT(void) __attribute__((signal,used)); \
	void INT_VECT(void)



#endif /* INTERRUPTS_H_ */