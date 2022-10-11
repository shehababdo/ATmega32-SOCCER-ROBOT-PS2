  unsigned char PS2byte;
  unsigned char PS2data4;
  unsigned char PS2data5;
  unsigned char i;

#include "gamepad.h"


#define SET(x,y) (x|=(1<<y))
#define CLR(x,y) (x&=(~(1<<y)))
#define CHK(x,y) (x & (1<<y))
#define TOG(x,y) (x^=(1<<y)) 

void ReadGamepad()
{
   SET(PS2PORT,PS2cmd); 
   SET(PS2PORT,PS2clk); 
   CLR(PS2PORT,PS2att); // low enable joystick

   Delay(1);
   PS2byte=0x01; // first command
   for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); //Delay(1); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 

   Delay(1);
   PS2byte=0x42; // sec command
   for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
	  //Delay(1); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 

   Delay(1);
   for(i=0;i<8;i++)  // 3 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); //Delay(1); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 

   Delay(1);
   PS2data4=0;
   for(i=0;i<8;i++)  // 4 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); Delay(1);
	  if(CHK(PS2IN,PS2dat)) SET(PS2data4,i); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 

   Delay(1);
   PS2data5=0;
   for(i=0;i<8;i++) // 5 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); Delay(1); 
	  if(CHK(PS2IN,PS2dat)) SET(PS2data5,i);
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   SET(PS2PORT,PS2att); // HI disable joystick
   
   		if (PS2data4==0xEF)   // check if bit 4 is low ---> GO FORWARD
   		{
		DIO_SetHigh(PORT_D,PIN_7);
		DIO_SetLow(PORT_D,PIN_6);
		
		DIO_SetHigh(PORT_D,PIN_2);
		DIO_SetLow(PORT_D,PIN_3);
   		} 
		else if (PS2data4==0xBF) // check if bit 6 is low ---> GO BACKWARD
		{
		DIO_SetHigh(PORT_D,PIN_6);
		DIO_SetLow(PORT_D,PIN_7);
		
		DIO_SetHigh(PORT_D,PIN_3);
		DIO_SetLow(PORT_D,PIN_2);
		}
}
