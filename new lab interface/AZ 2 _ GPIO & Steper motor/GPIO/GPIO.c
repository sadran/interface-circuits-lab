
#include "LPC17xx.h"

int main ()
{
	char temp = 1;
	LPC_GPIO2->FIODIR = 0x0F ;
	LPC_GPIO2->FIOCLR = 0x0F ;
	
	
	while(1)
	{
		LPC_GPIO2->FIOCLR = 0xF;
		
		while ( ( LPC_GPIO2 -> FIOPIN & ( 16 ) ) == 0 )
		{	
			int i =1000000 ; 
						
			if (temp == 1 )
			{
				LPC_GPIO2 -> FIOSET = 0xF;
			}
			else 
			{
				LPC_GPIO2 -> FIOCLR = 0xF; 
			}
			
			while(i != 0 )
			{
				i-- ; 
				if(i==0 && temp ==1)
					temp = 0 ; 
				else if(i==0 && temp == 0)
					temp = 1 ; 
			}
		}
	}	
}

