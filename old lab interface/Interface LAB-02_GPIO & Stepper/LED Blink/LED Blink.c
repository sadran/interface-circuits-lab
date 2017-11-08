#include <lpc17xx.h>

void delay (uint32_t Time)
{
	uint32_t  i;
	i = 0;
	while (Time--) {
		for (i = 0; i<5000 ; i++);
    }
}

int main(void)
{
	LPC_GPIO2->FIODIR = 0xff;
	LPC_GPIO2->FIOCLR = 0xff;   //turn off leds
	while(1)
	{	
		LPC_GPIO2->FIOSET = 0xFF;
		delay(500);
		LPC_GPIO2->FIOCLR = 0XFF;
		delay(500);
	}
}
