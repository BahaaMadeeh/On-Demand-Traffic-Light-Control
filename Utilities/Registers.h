/*
 * Registers.h
 *
 * Created: 9/5/2022 11:56:00 PM
 *  Author: Bahaa Madeeh
 */ 



#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "STD_TYPES.h"
#include "BIT_MATHS.h"



/* Group A Registers */

#define PORTA_REG  *((volatile uint8*)0x3B)
#define DDRA_REG   *((volatile uint8*)0x3A)
#define PINA_REG   *((volatile uint8*)0x39)

/* Group B Registers */
#define PORTB_REG  *((volatile uint8*)0x38)
#define DDRB_REG   *((volatile uint8*)0x37)
#define PINB_REG   *((volatile uint8*)0x36)

/* Group C Registers */
#define PORTC_REG  *((volatile uint8*)0x35)
#define DDRC_REG   *((volatile uint8*)0x34)
#define PINC_REG   *((volatile uint8*)0x33)

/* Group D Registers */
#define PORTD_REG  *((volatile uint8*)0x32)
#define DDRD_REG   *((volatile uint8*)0x31)
#define PIND_REG   *((volatile uint8*)0x30)

/***********************/
/* Timer Registers*/
/***********************/

#define TCCR0_REG   *((volatile uint8*)0x53)
#define TCNT0_REG   *((volatile uint8*)0x52)
#define TIFR_REG    *((volatile uint8*)0x58)
#define TIMSK_REG   *((volatile uint8*)0x59)

/************************************/
/*   Interrupts Registers           */
/************************************/

#define SREG_REG   *((volatile uint8*)0x5F)
#define GICR_REG   *((volatile uint8*)0x5B)
#define MCUCR_REG  *((volatile uint8*)0x55)

#endif /* REGISTERS_H_ */