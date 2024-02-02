/*
* ICU.c
*
* Created: 9/16/2023 7:37:07 PM
* Author : AMIT
*/
#include <avr/io.h>
#include <stdlib.h>
#include "LIB/stdTypes.h"

//#include "HAL/GLCD/GRLCD_Int.h"
#include "E:/Embeded_Systems/AVR_Projects/Test/HAL/GRLCD/GRLCD_Int.h"
#include <util\delay.h>
//#include "STD_TYPES.h"

//#include "DIO_interface.h"
#include "MCAL/DIO/DIO_int.h"
#include "MCAL/TMR/TMR_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"

#include "MCAL/GIE/GIE_int.h"
//#include "LCD_interface.h"


volatile static u16 SWICU_u16PeriodTicks=0;
volatile static u16 FREQ = 0 ;
volatile static u16 SWICU_u16OnTicks=0;

void SW_ICU(void);
void PWM_draw(u8 duty);





int main(void)
{
	/* pin OC0 output for HW PWM*/

	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_3,DIO_OUTPUT );
	/* INT0 pin input*/
	DIO_enuSetPinDirection(DIO_GROUP_D,DIO_PIN_2,DIO_INPUT);
	//DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	EXTI_voidPeripheralINTEnable(EXTI_INT0,EXTI_SENSE_RISING_EGDE);
	EXTI_callBackFunc_INT0(&SW_ICU);



	 GLCD_Init();
	 
	/*TIMERS INIT*/
	TIMER0_voidInit();
	TIMER1_voidInit();

/*GIE*/

GIE_vidEnable();

    GLCD_String(0," periodTick=         ");
    GLCD_DisplayVariable(1,SWICU_u16PeriodTicks*0.5);
   // GLCD_String(0,"FREQ");
//	GLCD_DisplayVariable(1,FREQ);
    //GLCD_DisplayVariable(1,SWICU_u16PeriodTicks*0.5);
	GLCD_String(2," Duty Cycle %          ");
	GLCD_DisplayVariable(3,SWICU_u16OnTicks*0.5);



	while (1)
	{
		

		 PWM_draw(SWICU_u16OnTicks*0.5);
		
	}
	
	
}

void SW_ICU(void)
{

	static u16 Local_u16Counter=0;
	Local_u16Counter++;
	if(Local_u16Counter == 1)
	{
		TIMER1_voidSetTimerValue(0);
	}
	if(Local_u16Counter == 2)
	{
		SWICU_u16PeriodTicks=TIMER1_voidgetTimerValue();

		EXTI_voidPeripheralINTEnable(EXTI_INT0,EXTI_SENSE_FALLING_EDGE);
		
	}
	if(Local_u16Counter == 3)
	{
		SWICU_u16OnTicks=TIMER1_voidgetTimerValue()-SWICU_u16PeriodTicks;
		EXTI_voidPeripheralINTDisbale(EXTI_INT0);

		//Local_u16Counter=0;
	}

}

void PWM_draw(u8 duty)
{

	if(duty<20)

	{
		GLCD_String(4, "-");
		GLCD_String(5, " |");
		GLCD_String(6, "  ---------");

	}

	else if(duty>=20 && duty< 30)
	{

		GLCD_String(4, "--");
		GLCD_String(5, "  |");
		GLCD_String(6, "   --------");

	}

	else if(duty>=30 && duty< 40)
	{
		GLCD_String(4, "---");
		GLCD_String(5, "   |");
		GLCD_String(6, "    -------");

	}

	else if(duty>=40 && duty< 50)
	{
		GLCD_String(4, "----");
		GLCD_String(5, "    |");
		GLCD_String(6, "     ------");

	}

	else if(duty>=50 && duty< 60)
	{
		GLCD_String(4, "-----");
		GLCD_String(5, "     |");
		GLCD_String(6, "      -----");

	}

	else if(duty>=60 && duty< 70)
	{
		GLCD_String(4, "------");
		GLCD_String(5, "      |");
		GLCD_String(6, "       ----");

	}

	else if(duty>=70 && duty< 80)
	{
		GLCD_String(4, "-------");
		GLCD_String(5, "       |");
		GLCD_String(6, "        ---");

	}

	else if(duty>=80 && duty< 90)
	{
		GLCD_String(4, "--------");
		GLCD_String(5, "        |");
		GLCD_String(6, "         --");
	}

	else if(duty>=90 )
	{
		GLCD_String(4, "---------     ");
		GLCD_String(5, "          |   ");
		GLCD_String(6, "           -  ");

	}

}


