
#include "app.h"
#include "../Utilities/Interrupts.h"
//#include <avr/interrupt.h>
uint8 normal_mode=1;
uint8 carLED=0;
uint8 prevcarLED=1;
//uint8 yellowFlag=0;

void APP_init(void)
{
	//Car LED initialization
	LED_init(LED_CAR_PORT,LED_CAR_GREEN_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_RED_PIN);

	//Pedestrian LED initialization
	LED_init(LED_PED_PORT,LED_PED_GREEN_PIN);
	LED_init(LED_PED_PORT,LED_PED_YELLOW_PIN);
	LED_init(LED_PED_PORT,LED_PED_RED_PIN);

	//Button initialization
	BUTTON_init(BUTTON_PORT,BUTTON_PIN);

	//Timer initialization
	Timer0_init();
	//enable OVF Interrupt timer0
	//OVF_INT_TIMER0();
	//Enable Global interrupts & setup rising edge detection for button
	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}

void APP_start()
{
	uint8 i;
	if(normal_mode || carLED==0 || carLED == 1)
	{
		if(!normal_mode)
		{
			carLED=1;
		}
		//configure PED LEDs
		LED_off(LED_PED_PORT,LED_PED_GREEN_PIN);
		LED_off(LED_PED_PORT,LED_PED_YELLOW_PIN);
		LED_off(LED_PED_PORT,LED_PED_RED_PIN);

		switch(carLED)
		{
			case 0: //GREEN LED
			LED_on(LED_CAR_PORT,LED_CAR_GREEN_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_RED_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);

			for(i=0;i<50;i++)
			{
				Timer0_delay(68);
				if(!normal_mode)break;
			}
			carLED=1;
			prevcarLED=0;
			break;

			case 1://yellow LED
			if(!normal_mode)
			{
				if(prevcarLED!=2)
				{
					LED_on(LED_PED_PORT,LED_PED_RED_PIN);
					for(i=0;i<5;i++)	 //blink both yellow leds
					{
						LED_on(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
						LED_on(LED_PED_PORT,LED_PED_YELLOW_PIN);
						Timer0_delay(390);
						LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
						LED_off(LED_PED_PORT,LED_PED_YELLOW_PIN);
						Timer0_delay(190);
						LED_on(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
						LED_on(LED_PED_PORT,LED_PED_YELLOW_PIN);
						Timer0_delay(390);
					}
				}
				prevcarLED=1;
				carLED=2;
				LED_on(LED_CAR_PORT,LED_CAR_RED_PIN);
			} else//blink car yellow leds
			{  for(i=0;i<5;i++)
				{
					LED_on(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
					Timer0_delay(380);
					LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
					Timer0_delay(180);
					LED_on(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
					Timer0_delay(380);
					if(!normal_mode)
					{
						prevcarLED=1;
						break;
					}
				}

			}
			LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
			LED_off(LED_PED_PORT,LED_PED_YELLOW_PIN);
			//configure variables
			if(prevcarLED==0)
			{
				carLED=2;
				prevcarLED=1;

			}else if(prevcarLED==2)
			{
				carLED=0;
				prevcarLED=1;
			}
			break;

			case 2://red led
			LED_off(LED_CAR_PORT,LED_CAR_GREEN_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
			LED_on(LED_CAR_PORT,LED_CAR_RED_PIN);
			for(i=0;i<50;i++)
			{
				Timer0_delay(68);
				if(!normal_mode)break;
			}
			prevcarLED=2;
			carLED=1;
			break;

			default:
			carLED=2;
			prevcarLED=1;
			break;
		}
	}else
	{
		LED_on(LED_PED_PORT,LED_PED_GREEN_PIN);
		LED_off(LED_PED_PORT,LED_PED_YELLOW_PIN);
		LED_off(LED_PED_PORT,LED_PED_RED_PIN);

		LED_off(LED_CAR_PORT,LED_CAR_GREEN_PIN);
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		LED_on(LED_CAR_PORT,LED_CAR_RED_PIN);
		Timer0_delay(5000);
		LED_off(LED_CAR_PORT,LED_CAR_RED_PIN);
		//blink both yellow leds
		for(i=0;i<5;i++)
		{
			LED_on(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
			LED_on(LED_PED_PORT,LED_PED_YELLOW_PIN);
			Timer0_delay(390);
			LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
			LED_off(LED_PED_PORT,LED_PED_YELLOW_PIN);
			Timer0_delay(190);
			LED_on(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
			LED_on(LED_PED_PORT,LED_PED_YELLOW_PIN);
			Timer0_delay(390);

		}
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		LED_off(LED_PED_PORT,LED_PED_YELLOW_PIN);
		LED_on(LED_PED_PORT,LED_PED_RED_PIN);
		normal_mode=1;
		carLED=0;
		prevcarLED=1;
	}

}
ISR(EXT_INT0)
{
	normal_mode=0;
}
