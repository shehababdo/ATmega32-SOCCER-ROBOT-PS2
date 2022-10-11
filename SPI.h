/*
 * SPI.h
 *
 * Created: 9/10/2021 11:16:17 AM
 *  Author: Shehab Abdo
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "../../COMMON/CPU_CONFIG.h"

void SPI_initMasterMode(void);
void SPI_initSlaveMode(void);
void SPI_SendByte(char data);
char SPI_ReceiveByte(void);
void SPI_SendStr(char *data);

#endif /* SPI_H_ */