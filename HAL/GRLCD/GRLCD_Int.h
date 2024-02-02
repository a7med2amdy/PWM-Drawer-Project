/*
 * GRLCD.h
 *
 *  Created on: Jan 11, 2024
 *      Author: hp
 */

#ifndef HAL_GRLCD_GRLCD_INT_H_
#define HAL_GRLCD_GRLCD_INT_H_


void GLCD_Init();			/*it init & moving indicator to start*/

void GLCD_Command(char Command);   /* GLCD command function */

void GLCD_Data(char Data);         /* GLCD data function */



void GLCD_String(char page_no, char *str);          /* GLCD string write function */

void intToAscii(int num, char* buffer, int bufferSize);

void GLCD_DisplayVariable(int page_no, int variable);

#endif /* HAL_GRLCD_GRLCD_INT_H_ */
