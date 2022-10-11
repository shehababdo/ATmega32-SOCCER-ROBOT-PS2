/*
 * SOCCER ROBOT.c
 *
 * Created: 10/1/2022 12:43:51 AM
 * Author : Shehab Abdo
 */ 

#include <avr/io.h>
#include "COMMON/CPU_CONFIG.h"
#include "MCAL/SPI/SPI.h"
#include "MCAL/DIO/DIO.h"
#include "ECU/DC_Motor/DC_Motor.h"
#include "ECU/PS2/PS2.h"

int main(void)
{
	DC_Init();

	
	
	DDRC=0XFF;
	// PSx controller I/O pin setup:
	set_bit(DDRB, PB7);                 // clock. output. (blue)
	
	clr_bit(DDRB, PB6);                 // data. input. (brown)
	set_bit(PORTB, PB6);               //    enable pull up resistor
	
 	clr_bit(DDRB, PB0);                 // acknolage. input. (green)
    set_bit(PORTB, PB0);               //  enable pullup resistor
	
	set_bit(DDRB, PB5);                 // command. output. (orange)
	
	set_bit(DDRB, PB4);                 // attention. output. (yellow)
	

	
	int_PS2inanalougemode();
	
	
	short int temp, data0, data1, data2, data3, data4, data5; 
	
	FORWARD();
	_delay_ms(500);
	BACKWARD();
	_delay_ms(500);
	STOP();
	
		
	while(1)
	{

		set_bit(PORTB, PB5);                          // start communication with PSx controller
		set_bit(PORTB, PB7);
		clr_bit(PORTB, PB4);
		
		gameByte(0x01);                                       // bite 0. header.
		temp = gameByte(0x42);                          // bite 1. header. (should possibly put test on this byte to detect unplugging of controller.)
		gameByte(0x00);                                       // bite 2. header.
		
		data0 = gameByte(0x00);                         // bite 3. first data bite.
		data1 = gameByte(0x00);                         // bite 4.
		data2 = gameByte(0x00);                         // bite 5.
		data3 = gameByte(0x00);                         // bite 6.
		data4 = gameByte(0x00);                         // bite 7.
		data5 = gameByte(0x00);                         // bite 8.
		
		_delay_us(1);
		set_bit(PORTB, PB5);                      // close communication with PSx controller
		_delay_us(1);
		set_bit(PORTB, PB4);                        // all done.

			
/*
		switch (data0)
		{
			printf("data=%X\n",data0);
		case 0xEF:
		{
// 			set_bit(DDRC, PC2);
// 			set_bit(PORTC, PC2);
			FORWARD();
			break;
		}
		case 0x7F:
		{
// 			set_bit(DDRC, PC7);
// 			set_bit(PORTC, PC7);
			BACKWARD();
			break;
		}
		case 0xBF:
		{
// 			set_bit(DDRC, PC2);
// 			clr_bit(PORTC, PC2);
			RIGHT();
			break;
		}
		case 0xDF:
		{
// 			set_bit(DDRC, PC7);
// 			clr_bit(PORTC, PC7);
			LEFT();
			break;
		}
		

		}*/
	if (data0==0xEF||data1==0xEF)
	{
		FORWARD();
	} 
	else if (data0==0x7F||data1==0x7F)
	{
		BACKWARD();
	}
	else if (data0==0xBF||data1==0xBF)
	{
		RIGHT();
	}
	else if (data0==0xDF||data1==0xDF)
	{
		LEFT();
	}
	else
	{
		//STOP();
		/*continue;*/
	}
	}
}


