/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: TIMERS             *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE: 9/9/2023          *************************/
/***********************************************************************/
/***********************************************************************/


#include "../../LIB/stdTypes.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error_State.h"


#include "TMR_config.h"
#include "TMR_private.h"
#include "TMR_register.h"
#include "TMR_interface.h"


static void (*ptrToFunc_ovf)(void)=NULL;
static void (*ptrToFunc_ctc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/*set fast PWM mode */
	SET_BIT(TIMER_TCCR0,TMR_WGM00);
	SET_BIT(TIMER_TCCR0,TMR_WGM01);
	
	/*NON INVERTING*/
	CLR_BIT(TIMER_TCCR0,TMR_COM00);
	SET_BIT(TIMER_TCCR0,TMR_COM01);
		
		/*prescaler*/
		TIMER_TCCR0 &=0b11111000;
		TIMER_TCCR0 |=2;
		
	/*compare match value to 32us on time*/
	TIMER_OCR0=64;
	
}


u8 TIMER0_setCallBack(u8 copy_u8IntID,void (*ptrToFunc)(void))
{

	u8 Error_state=OK;

	if(ptrToFunc != NULL)
	{
		if(copy_u8IntID == TIMER_OVF_INT)
		{
			ptrToFunc_ovf=ptrToFunc;
		}
		else if(copy_u8IntID==TIMER_CTC_INT)
		{
			ptrToFunc_ctc=ptrToFunc;
		}
		else
		{
			Error_state=NOK;
		}
		
		
	}
	else
	{
		Error_state=NULL_POINTER;
	}


	return Error_state;
}

void TIMER1_voidInit(void)
{
	/*Set normal mode*/
	CLR_BIT(TIMER1_TCCR1A,TIMER1_COM1A0);
	CLR_BIT(TIMER1_TCCR1A,TIMER1_COM1A1);
	
	/*Set waveform generation mode normal */
	CLR_BIT(TIMER1_TCCR1A,TIMER1_WGM10);
	CLR_BIT(TIMER1_TCCR1A,TIMER1_WGM11);
	CLR_BIT(TIMER1_TCCR1B,TIMER1_WGM12);
	CLR_BIT(TIMER1_TCCR1B,TIMER1_WGM13);
	
	/*prescaler :Division by 8*/
	CLR_BIT(TIMER1_TCCR1B,TIMER1_CS10);
	SET_BIT(TIMER1_TCCR1B,TIMER1_CS11);
	CLR_BIT(TIMER1_TCCR1B,TIMER1_CS12);
	
}

void TIMER1_voidSetTimerValue(u16 copy_u16TimerValue)
{
	TIMER1_TCNT1=copy_u16TimerValue;
}
u16 TIMER1_voidgetTimerValue(void)
{
	return TIMER1_TCNT1;
}

void TIMER1_voidSetCompareValueChannelA(u16 copy_u16CompareValue)
{
	/*set compare value*/
	TIMER1_OCR1A=copy_u16CompareValue;
}


/*ISR CTC MODE*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
ptrToFunc_ctc();
}


/*ISR OVF MODE*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	ptrToFunc_ovf();
}
