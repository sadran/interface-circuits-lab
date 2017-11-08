#include "lpc17xx.h"

int main()
{
	LPC_PINCON -> PINSEL3 = 2<<8 ;			//SET P1.20 FOR PWM
	LPC_PWM1 -> TCR = 0x2 ;							//RESET TIMER FOR PWM
	LPC_PWM1->MCR = 0x2;								//
	LPC_PWM1-> PCR = 1<<10;
	LPC_PWM1->MR0 = 50000000;
	LPC_PWM1->MR2 = 40000000;
	LPC_PWM1->TCR = 0x1;
	while(1);
	
}

