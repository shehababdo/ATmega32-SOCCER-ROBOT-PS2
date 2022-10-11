#ifndef GAMEPAD_H_
#define GAMEPAD_H_

  unsigned char PS2byte;
 extern unsigned char PS2data4;
 extern unsigned char PS2data5;
  unsigned char i;


#define PS2clk 7
#define PS2cmd 5
#define PS2att 4
#define PS2dat 6
#define PS2PORT PORTB
#define PS2IN PINB

#include <avr/io.h>
#include "../../MCAL/delay/delays.h"
#include "../../COMMON/CPU_CONFIG.h"
#include "../../MCAL/DIO/DIO.h"
void ReadGamepad();

#endif /* GAMEPAD_H_ */