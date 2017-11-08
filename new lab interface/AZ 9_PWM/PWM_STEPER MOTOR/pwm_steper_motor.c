#include "lpc17xx.h"

int main()
{		
	LPC_PINCON->PINSEL3 = ( 2<<8 ) | (2<<10) | ( 2<<14 ) | ( 2<<16) ;
	LPC_PWM1-> TCR = 0x2 ; 
	LPC_PWM1-> MCR = 0x2 ;
	
	LPC_PWM1->PCR = (1<<3)|(1<<4)|(1<<5)|(1<<10)|(1<<11)|(1<<12)|(1<<13); //(p1.20, p1.21, p1.23, p1.24)
	LPC_PWM1->MR0 = 4000000;
	LPC_PWM1->MR2 = 1000000;
	LPC_PWM1->MR3 = 2000000;
	LPC_PWM1->MR4 = 3000000;
	LPC_PWM1->MR5 = 4000000;
	
	LPC_PWM1->TCR = 0x1;
	while (1);
	
}

