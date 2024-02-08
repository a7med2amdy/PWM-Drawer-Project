#ifndef _TIMERS_REGISTER_H_
#define _TIMERS_REGISTER_H_
					        
#define TIMER_OCR0          (*((volatile u8*)0X5C))
#define TIMER_TCCR0         (*((volatile u8*)0X53))
#define TIMER_TCNT0         (*((volatile u8*)0X52))
#define TIMER_TIMSK         (*((volatile u8*)0X59))
#define TIMER_TIFR          (*((volatile u8*)0X58))

/*TIMER 1*/
#define TIMER1_TCCR1A       (*((volatile u8*)0X4F))
#define TIMER1_COM1A1          7
#define TIMER1_COM1A0          6
#define TIMER1_COM1B1          5
#define TIMER1_COM1B0          4
#define TIMER1_WGM11           1
#define TIMER1_WGM10           0     


#define TIMER1_TCCR1B     (*((volatile u8*)0X4E))
#define TIMER1_WGM13           4
#define TIMER1_WGM12           3
#define TIMER1_CS12            2
#define TIMER1_CS11            1
#define TIMER1_CS10            9
  	
	  
#define TIMER1_OCR1A     (*((volatile u16*)0X4A))
#define TIMER1_ICR1      (*((volatile u16*)0X46))
#define TIMER1_TCNT1     (*((volatile u16*)0X4C))
		
#endif	
		
		