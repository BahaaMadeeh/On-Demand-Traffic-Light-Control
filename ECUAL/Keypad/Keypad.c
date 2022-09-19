/*
 * Keypad.c
 *
 * Created: 9/16/2022 2:18:20 AM
 *  Author: Bahaa Madeeh
 */ 
 #include "Keypad.h"
 const uint8 KPD_SwitchValue[4][4]=
 {
	 {0x04, 0x08, 0x0C, 0x10},
	 {0x03, 0x07, 0x0B, 0x0F},
	 {0x02, 0x06, 0x0A, 0x0E},
	 {0x01, 0x05, 0x09, 0x0D}
 };
 
 uint8 KPD_GetPressedKey(void)
 {
	 /* variables for the location of columns and rows */
	uint8 LOC_Column, LOC_Row, LOC_Return=NOT_PRESSED;
	
	/*Looping on columns */
	for(LOC_Column=0+COLUMN_INIT; LOC_Column<COLUMN_FINAL; LOC_Column++)
	{
		/* Activate columns */
		DIO_write(KPD_PORT, LOC_Column, LOW);
		
		/* Looping on rows */
		for(LOC_Row=0+ROW_INIT; LOC_Row<ROW_FINAL; LOC_Row++)
		{
			/* Check the status of the switch */
			if(!DIO_read(KPD_PORT,LOC_Row))
			{
				/*Get the current value when pressed */
				LOC_Return=KPD_SwitchValue[LOC_Column-COLUMN_INIT][LOC_Row-ROW_INIT];
				
				/* Wait until the switch is released (single press) */
				while(!DIO_read(KPD_PORT,LOC_Row)); //busy wait
				
				/* Delay to avoid bouncing */
				_delay_ms(10);
			}
		}
		/* Deactivate the column */
		DIO_write(KPD_PORT,LOC_Column,HIGH);
	}
	return LOC_Return;	 
 }