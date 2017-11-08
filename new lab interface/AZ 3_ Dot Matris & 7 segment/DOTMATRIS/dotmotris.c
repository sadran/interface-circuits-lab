#include "lpc17xx.h"


//SHOW NUM 12 IN DOTMATRIS

void delay(int time);

int main()
{
	int c = 1 ;
	//int r = 1 ;
	LPC_GPIO2 -> FIODIR = 0xFF;
	LPC_GPIO2 -> FIOCLR = 0xFF;
	
	LPC_GPIO0 -> FIODIR = 0xFF;
	LPC_GPIO0 -> FIOCLR = 0xFF;
	
	while (1)
	{
		for( ; c <129 ; c = c*2)
		{
			LPC_GPIO0 ->FIOSET = c ;
			switch (c)
			{
				case 1 : 
					LPC_GPIO2 -> FIOSET = 0x4;
					break;
				case 2 :
					LPC_GPIO2 -> FIOSET = 0x2;
					break;
				case 4 :
					LPC_GPIO2 -> FIOSET = 0xFF;
					break;
				case 8 :
					LPC_GPIO2 -> FIOSET = 0x00;
					break;
				case 16:
					LPC_GPIO2 -> FIOSET = 0xE2;
					break;
				case 32:
					LPC_GPIO2 -> FIOSET = 0xA1;
					break;
				case 64:
					LPC_GPIO2 -> FIOSET = 0x91;
					break;
				default:
					LPC_GPIO2 -> FIOSET = 0x8E;
			}				
			delay(50000);
			LPC_GPIO2 ->FIOCLR =0xFF;
			LPC_GPIO0 ->FIOCLR =0xFF;
		}
		c = 1;
			 
	}
		
}


void delay(int time)
{
int t=0;
	for( ; t<time ; t++);
}

