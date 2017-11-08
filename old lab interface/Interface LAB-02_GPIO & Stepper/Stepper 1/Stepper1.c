#include <lpc17xx.h>

void delay (uint32_t Time)
{
	uint32_t  i;
	i = 0;
	while (Time--){
		for (i = 0 ; i<5000 ; i++);
	}
}
int main(void)
{
	LPC_GPIO2->FIODIR0 = 0x0F;       //turn off
	while(1)
	{
		LPC_GPIO2->FIOPIN = 0x01;
		delay(100);
  		LPC_GPIO2->FIOPIN = 0x02;
		delay(100);
		LPC_GPIO2->FIOPIN = 0x04;
		delay(100);
		LPC_GPIO2->FIOPIN = 0x08;
		delay(100);
	}
}
