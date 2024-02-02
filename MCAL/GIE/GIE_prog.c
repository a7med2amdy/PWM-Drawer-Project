/*
 * GIE_prog.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#define SREG 		*((volatile unsigned char*)0x5F)

void GIE_vidEnable(void)
{
	SREG |= (1<<7);
//	asm("sei");
//volatile __asm("SEI");
//	__asm__("sei");
}

void GIE_vidDisable(void)
{
	//volatile __asm("CLI");
	SREG &=~(1<<7);
}


