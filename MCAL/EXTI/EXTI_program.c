
#include "../../LIB/stdTypes.h"
#include "../../LIB/BIT_MATH.h"
//#include "Error_State.h"

#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"


void (*ptr_INT0)(void)=NULL;
void (*ptr_INT1)(void)=NULL;
void (*ptr_INT2)(void)=NULL;


void EXTI_voidPeripheralINTEnable(u8 copy_u8IntID,u8 copy_u8SenseMode)
{
	/*enable pie*/
	SET_BIT(EXTI_GICR,copy_u8IntID);

	switch (copy_u8IntID)
	{
		case EXTI_INT0:
		
		switch(copy_u8SenseMode)
		{
			case EXTI_SENSE_LOW_LEVEL:  CLR_BIT(EXTI_MCUCR,ISC00);   CLR_BIT(EXTI_MCUCR,ISC01);    break;
			case EXTI_SENSE_FALLING_EDGE:CLR_BIT(EXTI_MCUCR,ISC00); SET_BIT(EXTI_MCUCR,ISC01);
			
			break;
			case EXTI_SENSE_RISING_EGDE:
			SET_BIT(EXTI_MCUCR,ISC00);
			SET_BIT(EXTI_MCUCR,ISC01);
			
			break;
			case EXTI_SENSE_ON_CHANGE:
			SET_BIT(EXTI_MCUCR,ISC00);
			CLR_BIT(EXTI_MCUCR,ISC01);
			break;
			default:/*error*/ break;

		}
		
		break;
		
		case EXTI_INT1:
		

		
		switch(copy_u8SenseMode)
		{
			case EXTI_SENSE_LOW_LEVEL:
			
			CLR_BIT(EXTI_MCUCR,ISC10);
			CLR_BIT(EXTI_MCUCR,ISC11);
			
			break;
			case EXTI_SENSE_FALLING_EDGE:
			CLR_BIT(EXTI_MCUCR,ISC10);
			SET_BIT(EXTI_MCUCR,ISC11);
			
			break;
			case EXTI_SENSE_RISING_EGDE:
			SET_BIT(EXTI_MCUCR,ISC10);
			SET_BIT(EXTI_MCUCR,ISC11);
			
			break;
			case EXTI_SENSE_ON_CHANGE:
			SET_BIT(EXTI_MCUCR,ISC10);
			CLR_BIT(EXTI_MCUCR,ISC11);
			break;
			default:/*error*/ break;

		}

		break;
		case EXTI_INT2:
		
		switch(copy_u8SenseMode)
		{
			
			case EXTI_SENSE_FALLING_EDGE:
			CLR_BIT(EXTI_MCUCSR,ISC2);
			break;
			case EXTI_SENSE_RISING_EGDE:
			SET_BIT(EXTI_MCUCSR,ISC2);
			
			break;
			
			default:/*error*/ break;

		}
		
		break;
		
		default:/*error*/ break;
	}
	


}
void EXTI_voidPeripheralINTDisbale(u8 copy_u8IntID)
{
	CLR_BIT(EXTI_GICR,copy_u8IntID);
}

void EXTI_callBackFunc_INT0(void(*ptr_func)(void))
{
	ptr_INT0=ptr_func;
	
}

void EXTI_callBackFunc_INT1(void(*ptr_func)(void))
{
	ptr_INT1=ptr_func;
	
}

void EXTI_callBackFunc_INT2(void(*ptr_func)(void))
{
	ptr_INT2=ptr_func;
	
}

/*INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void) 
{
	
	ptr_INT0();
}
/*INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{

ptr_INT1();
}

/*INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
ptr_INT2();
}
