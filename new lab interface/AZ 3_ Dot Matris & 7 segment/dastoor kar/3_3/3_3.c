#include "lpc17xx.h"


//SHOW NUM 12 IN DOTMATRIS

void delay(int time);

int main()
{
	int i; 
	int c ;
	int step ;
	int temp;
	int r[] = {0x4, 0x2, 0xFF, 0x00, 0xE2, 0xA1, 0x91, 0x8E};
	//int r = 1 ;
	LPC_GPIO2 -> FIODIR = 0xFF;
	LPC_GPIO2 -> FIOCLR = 0xFF;
	
	LPC_GPIO0 -> FIODIR = 0xFF;
	LPC_GPIO0 -> FIOCLR = 0xFF;
	
	while (1)
	{
		for(step =0 ; step <10  ; step++)
		{
			for(c = 1 ; c <129 ; c = c*2)
			{
				LPC_GPIO0 ->FIOSET = c ;
				switch (c)
				{
					case 1 : 
						LPC_GPIO2 -> FIOSET = r[0];
						break;
					case 2 :
						LPC_GPIO2 -> FIOSET = r[1];
						break;
					case 4 :
						LPC_GPIO2 -> FIOSET = r[2];
						break;
					case 8 :
						LPC_GPIO2 -> FIOSET = r[3];
						break;
					case 16:
						LPC_GPIO2 -> FIOSET = r[4];
						break;
					case 32:
						LPC_GPIO2 -> FIOSET = r[5];
						break;
					case 64:
						LPC_GPIO2 -> FIOSET = r[6];
						break;
					default:
						LPC_GPIO2 -> FIOSET = r[7];
				}				
				delay(50000);
				LPC_GPIO2 ->FIOCLR =0xFF;
				LPC_GPIO0 ->FIOCLR =0xFF;
			}
			
		}
		temp = r[7];
		for(i = 7 ; i>0 ; i--)
		{
			r[i]=r[i-1];
		}
		r[0]=temp;
	}
		
}


void delay(int time)
{
int t=0;
	for( ; t<time ; t++);
}

