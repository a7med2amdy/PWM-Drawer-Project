/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC:    EXTI            *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE: 25/8/2023         *************************/
/***********************************************************************/
/***********************************************************************/

#define EXTI_INT0     6
#define EXTI_INT1     7
#define EXTI_INT2     5

/*SENSE_CTRL*/
#define EXTI_SENSE_LOW_LEVEL      0  
#define EXTI_SENSE_FALLING_EDGE   1  
#define EXTI_SENSE_RISING_EGDE    2
#define EXTI_SENSE_ON_CHANGE      3



void EXTI_voidPeripheralINTEnable(u8 copy_u8IntID,u8 copy_u8SenseMode);
void EXTI_voidPeripheralINTDisbale(u8 copy_u8IntID);
void EXTI_callBackFunc_INT1(void(*ptr_func)(void));
void EXTI_callBackFunc_INT0(void(*ptr_func)(void));
void EXTI_callBackFunc_INT2(void(*ptr_func)(void));
