#include <lpc17xx.h>
unsigned k = 0;
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
	LPC_GPIO2->FIODIR0 = 0x0F; 
	for(k = 0 ; k<3 ; k++)
	{
		LPC_GPIO2->FIOPIN = 0x08;
		delay(10000);
		LPC_GPIO2->FIOPIN = 0x04;
		delay(10000);
		LPC_GPIO2->FIOPIN = 0x02;
		delay(10000);
		LPC_GPIO2->FIOPIN = 0x01;
		delay(10000);
	}
}

