#include <lpc17xx.h>

void delay (uint32_t Time)
{
	uint32_t  i;
	i = 0;
	while (Time--){
		for (i = 0 ; i<5000 ; i++);	}
}

int main (void)
{
	LPC_GPIO2->FIODIR = 0x1;
	LPC_GPIO2->FIOCLR = 0x1;
	while(1)
	{
		LPC_GPIO2->FIOCLR = 0x1;	
		while((LPC_GPIO2->FIOPIN & 1 << 1) == 0)
		{
			LPC_GPIO2->FIOPIN = 0x1;
		}
	}
}
