/*
 * DC_Motor.h
 *
 * Created: 10/2/2022 2:38:18 PM
 *  Author: Shehab Abdo
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../COMMON/CPU_CONFIG.h"
void DC_Init(void);
void FORWARD(void);
void BACKWARD (void);
void LEFT (void);
void RIGHT (void);
void STOP (void);
#endif /* DC_MOTOR_H_ */