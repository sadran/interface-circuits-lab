#include "lpc17xx.h"

void delay(int s );

int main()
{
	int steper = 1; 
	int degree = 0;
	LPC_GPIO2 -> FIODIR = 0xF;
	LPC_GPIO2 -> FIOCLR = 0xF; 
	

	while (1)
	{
		
		degree = 0;
		for( ;degree < 360 ; degree = degree + 15 )                                 //rast gard
		{
			steper = 1;
			for( ; steper < 9 ; steper = steper *2 )
			{
				LPC_GPIO2 -> FIOPIN = steper; 
				delay(500000);
			}
			delay(2500000);
		}
		
	 degree = 0;
		for ( ; degree < 180 ; degree = degree +15)														//chap gard
		{
			steper = 8;
			for( ; steper >= 1 ; steper = steper / 2 )
			{
				LPC_GPIO2 -> FIOPIN = steper; 
				delay(500000);
			}
			delay(2500000);
		}
	
	
 
	}
}

void delay(int s )
{	
	int x;
	for (x=0 ; x!=s ; x++);
}

