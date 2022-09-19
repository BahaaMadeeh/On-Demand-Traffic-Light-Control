/*
 * TWI.c
 *
 * Created: 9/16/2022 11:10:43 PM
 *  Author: Bahaa Madeeh
 */ 
#include "TWI.h"

void TWI_init(void)
{
	TWSR = 0x00;				/* Choose Prescalar */
	TWBR = BITRATE(TWSR);		/* Set bit rate */
}

uint8 TWI_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT))); //CHECK FLAG TWINT
	if((TWSR&0xF8)!=START_STATE)
	{
		return START_NOT_SENT;
	}else
	{
		return EVENT_OK;
	}
}

uint8 TWI_Repeated_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT))); //CHECK FLAG TWINT
	if((TWSR&0xF8)!=REPEATED_START_STATE)
	{
		return REPEATED_START_NOT_SENT;
	}else
	{
		return EVENT_OK;
	}
}

uint8 TWI_Address_Select(uint8 address, uint8 rw)
{
	uint8 status;
	if(rw == WRITE)
	{
		TWDR = address + 0;			/* write SLA+W in TWI data register */
	}else if(rw == READ)
	{
		TWDR = address + 1;			/* write SLA+R in TWI data register */
	}else
	{
		/* do nothing */
	}
	
	TWCR = (1<<TWEN)|(1<<TWINT);		/* Enable TWI & clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));		/* Wait till TWI finish its current operation*/
	status = TWSR & 0xF8;				/* Read TWI status register */
	if(status == SLA_W_ACK_STATE)		/* Check for SLA+W transmitted & ACK received */
	{
		return SLA_W_ACK_SENT;
	}else if(status == SLA_W_NACK_STATE)
	{
		return SLA_W_NACK_SENT;
	}
	if(status == SLA_R_ACK_STATE)		/* Check for SLA+R transmitted & ACK received */
	{
		return SLA_R_ACK_SENT;
	}else if(status == SLA_R_NACK_STATE)
	{
		return SLA_R_NACK_SENT;
	}else
	{
		return SLA_RW_FAILED;
	}				
}

uint8 TWI_data_event(uint8 *data, uint8 rw, uint8 ack)
{
	uint8 status;
	if(rw == WRITE)
	{
		TWDR = *data;						/* Copy data in TWI data register */
		TWCR=(1<<TWEN)|(1<<TWINT);			/* Enable TWI and clear interrupt flag */
		while (!(TWCR & (1<<TWINT)));		/* Wait till TWI finish its current operation*/
		status = TWSR & 0xF8;				/* Read TWI status register */
		if(status == DATA_WRITE_ACK_STATE)
		{
			return DATA_WRITE_ACK_SENT;
		}else if(status == DATA_WRITE_NACK_STATE)
		{
			return DATA_WRITE_NACK_SENT;
		}else
		{
			return DATA_WRITE_FAILED;
		}
	}else if(rw == READ)
	{
		if(ack == ACK)
		{
			TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);			/* Enable TWI, generation of ACK */
		}else if(ack == NACK)
		{
			TWCR = (1<<TWINT)|(1<<TWEN);					/* Enable TWI, with no ACK */
		}
		
		while (!(TWCR & (1<<TWINT)));						/* Wait till TWI finish its current operation*/
		*data = TWDR										/* Read data */
		status = TWSR & 0xF8;								/* Read TWI status register */
		
		if(status == DATA_READ_ACK_STATE)
		{
			return DATA_READ_ACK_SENT;
		}else if(status == DATA_READ_NACK_STATE)
		{
			return DATA_READ_NACK_SENT;
		}else
		{
			return DATA_READ_FAILED;
		}
	}
}

void TWI_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);	   /* Generate TWI stop */
	while (TWCR & (1<<TWSTO));
}