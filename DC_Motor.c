/*
 * DC_Motor.c
 *
 * Created: 10/2/2022 2:38:29 PM
 *  Author: Shehab Abdo
 */ 
#include "DC_Motor.h"
void DC_Init(void)
{
	//initialziation for Motor 1&2
	
	//MOTOR 1
	DIO_SetDir(PORT_D,PIN_7,OUTPUT);
	DIO_SetDir(PORT_D,PIN_6,OUTPUT);
	DIO_SetDir(PORT_D,PIN_4,OUTPUT);
	DIO_SetHigh(PORT_D,PIN_4);
	//MOTOR 2
	DIO_SetDir(PORT_D,PIN_3,OUTPUT);
	DIO_SetDir(PORT_D,PIN_2,OUTPUT);
	DIO_SetDir(PORT_D,PIN_5,OUTPUT);
	DIO_SetHigh(PORT_D,PIN_5);
}

void FORWARD(void)
{
	DIO_SetHigh(PORT_D,PIN_7);
	DIO_SetLow(PORT_D,PIN_6);
	
	DIO_SetHigh(PORT_D,PIN_2);
	DIO_SetLow(PORT_D,PIN_3);
}

void BACKWARD (void)
{
	DIO_SetHigh(PORT_D,PIN_6);
	DIO_SetLow(PORT_D,PIN_7);
	
	DIO_SetHigh(PORT_D,PIN_3);
	DIO_SetLow(PORT_D,PIN_2);
}

void LEFT (void)
{
	DIO_SetHigh(PORT_D,PIN_7);
	DIO_SetLow(PORT_D,PIN_6);
	
	DIO_SetHigh(PORT_D,PIN_3);
	DIO_SetLow(PORT_D,PIN_2);
}

void RIGHT (void)
{
	DIO_SetHigh(PORT_D,PIN_6);
	DIO_SetLow(PORT_D,PIN_7);
	
	DIO_SetHigh(PORT_D,PIN_2);
	DIO_SetLow(PORT_D,PIN_3);
}
void STOP (void)
{
	DIO_SetLow(PORT_D,PIN_6);
	DIO_SetLow(PORT_D,PIN_7);
			
	DIO_SetLow(PORT_D,PIN_3);
	DIO_SetLow(PORT_D,PIN_2);
}