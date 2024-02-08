

#ifndef _TIMERS_INTERFACE_H_
#define _TIMERS_INTERFACE_H_

#define TIMER_OVF_INT 0
#define TIMER_CTC_INT 1


void TIMER0_voidInit(void);
u8 TIMER0_setCallBack(u8 copy_u8IntID,void (*ptrToFunc)(void));


void TIMER1_voidInit(void);
void TIMER1_voidSetCompareValueChannelA(u16 copy_u16CompareValue);
void TIMER1_voidSetTimerValue(u16 copy_u16TimerValue);
u16 TIMER1_voidgetTimerValue(void);


#endif