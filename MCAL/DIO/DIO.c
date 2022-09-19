/*
 * DIO.c
 *
 * Created: 9/5/2022 5:58:39 PM
 *  Author: Bahaa Madeeh
 */ 
#include "DIO.h"



void DIO_init(uint8 PortNo, uint8 PinNo, uint8 Direction)
{
	if (Direction == INPUT)
	{
		switch (PortNo)
		{
			case GROUPA:
			CLEAR_BIT(DDRA_REG, PinNo);
			break;
			case GROUPB:
			CLEAR_BIT(DDRB_REG, PinNo);
			break;
			case GROUPC:
			CLEAR_BIT(DDRC_REG, PinNo);
			break;
			case GROUPD:
			CLEAR_BIT(DDRD_REG, PinNo);
			break;
		}
	}
	else if (PortNo == OUTPUT)
	{
		switch (PortNo)
		{
			case GROUPA:
			SET_BIT(DDRA_REG, PinNo);
			break;
			case GROUPB:
			SET_BIT(DDRB_REG, PinNo);
			break;
			case GROUPC:
			SET_BIT(DDRC_REG, PinNo);
			break;
			case GROUPD:
			SET_BIT(DDRD_REG, PinNo);
			break;
		}
	}
	else
	{

	}
}

void DIO_write(uint8 PortNo, uint8 PinNo, uint8 Value)
{
	if (Value == LOW)
	{
		switch (PortNo)
		{
			case GROUPA:
			CLEAR_BIT(PORTA_REG, PinNo);
			break;
			case GROUPB:
			CLEAR_BIT(PORTB_REG, PinNo);
			break;
			case GROUPC:
			CLEAR_BIT(PORTC_REG, PinNo);
			break;
			case GROUPD:
			CLEAR_BIT(PORTD_REG, PinNo);
			break;
		}
	}
	else if (Value == HIGH)
	{
		switch (PortNo)
		{
			case GROUPA:
			SET_BIT(PORTA_REG, PinNo);
			break;
			case GROUPB:
			SET_BIT(PORTB_REG, PinNo);
			break;
			case GROUPC:
			SET_BIT(PORTC_REG, PinNo);
			break;
			case GROUPD:
			SET_BIT(PORTD_REG, PinNo);
			break;
		}
	}
}

void DIO_read(uint8 PortNo, uint8 PinNo, uint8 *value)
{
	
	switch (PortNo)
	{
		case GROUPA:
		*value = GET_BIT(PINA_REG, PinNo);
		break;
		case GROUPB:
		*value = GET_BIT(PINB_REG, PinNo);
		break;
		case GROUPC:
		*value = GET_BIT(PINC_REG, PinNo);
		break;
		case GROUPD:
		*value = GET_BIT(PIND_REG, PinNo);
		break;
	}
	
}

void DIO_tog(uint8 PortNo, uint8 PinNo)
{
	switch(PortNo)
	{
		case GROUPA:
		TOG_BIT(PORTA_REG,PinNo);
		break;
		case GROUPB:
		TOG_BIT(PORTB_REG,PinNo);
		break;
		case GROUPC:
		TOG_BIT(PORTC_REG,PinNo);
		break;
		case GROUPD:
		TOG_BIT(PORTD_REG,PinNo);
		break;
	}
}

void DIO_SetGroupDirection(uint8 PortNo , uint8 Direction)
{
	switch (PortNo)
	{
		case GROUPA:
		DDRA_REG = Direction;
		break;
		case GROUPB:
		DDRB_REG = Direction;
		break;
		case GROUPC:
		DDRC_REG= Direction;
		break;
		case GROUPD:
		DDRD_REG= Direction;
		break;
	}
}

void DIO_SetGroupValue(uint8 PortNo , uint8 Value)
{

	switch (PortNo)
	{
		case GROUPA:
		PORTA_REG = Value;
		break;
		case GROUPB:
		PORTB_REG = Value;
		break;
		case GROUPC:
		PORTC_REG = Value;
		break;
		case GROUPD:
		PORTD_REG = Value;
		break;
	}
}
