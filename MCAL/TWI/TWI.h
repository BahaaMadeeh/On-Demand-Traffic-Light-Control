/*
 * TWI.h
 *
 * Created: 9/16/2022 11:10:34 PM
 *  Author: Bahaa Madeeh
 */ 


#ifndef TWI_H_
#define TWI_H_
#include <avr/io.h>
#include <math.h>
#define F_CPU 8000000U
#define SCL_CLK 400000U

/* Define bit rate */
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

#define WRITE	0
#define READ	1

#define ACK		0
#define NACK	1

/* States */
#define START_STATE					0x08
#define REPEATED_START_STATE		0x10
#define SLA_W_ACK_STATE				0x18
#define SLA_W_NACK_STATE			0x20
#define SLA_R_ACK_STATE				0x40
#define SLA_R_NACK_STATE			0x48
#define DATA_WRITE_ACK_STATE		0x28
#define DATA_WRITE_NACK_STATE		0x30
#define DATA_READ_ACK_STATE			0x50
#define DATA_READ_NACK_STATE		0x58

/* Returns */
#define EVENT_OK					0
#define START_NOT_SENT				1
#define REPEATED_START_NOT_SENT		2
#define SLA_W_ACK_SENT				3
#define SLA_W_NACK_SENT				4
#define SLA_R_ACK_SENT				5
#define SLA_R_NACK_SENT				6
#define SLA_RW_FAILED				7
#define DATA_WRITE_ACK_SENT			8
#define DATA_WRITE_NACK_SENT		9
#define DATA_WRITE_FAILED			10
#define DATA_READ_ACK_SENT			11
#define DATA_READ_NACK_SENT			12
#define DATA_READ_FAILED			13

void TWI_init(void);
uint8 TWI_start(void);
uint8 TWI_Repeated_start(void);
uint8 TWI_Address_Select(uint8 address, uint8 rw);
uint8 TWI_data_event(uint8 *data, uint8 rw, uint8 ack);
void TWI_stop(void);




#endif /* TWI_H_ */