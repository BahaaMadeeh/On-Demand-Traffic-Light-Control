/*
 * SPI.h
 *
 * Created: 9/16/2022 5:42:16 AM
 *  Author: Bahaa Madeeh
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>
#include "../DIO/DIO.h"
#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/BIT_MATHS.h"
/*___________________macros__________________  */
#define MOSI		PIN5
#define MISO		PIN6
#define SCK			PIN7
#define SS			PIN4
#define SPI_PORT	GROUPB 

void SPI_init(void);
void SPI_SendCommand(uint8 command);
uint8 SPI_Recieve(void);


#endif /* SPI_H_ */