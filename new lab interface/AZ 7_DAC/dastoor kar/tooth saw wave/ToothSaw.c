#include "lpc17xx.h"

int main()
{
	uint16_t i ;
LPC_PINCON->PINSEL1 = 2<<20;
	
while(1)
{
	for(i=0 ; i<4096 ; i++)
	{
		LPC_DAC->DACR = i;
	}
	
}

}

