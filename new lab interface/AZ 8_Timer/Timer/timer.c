#include "lpc17xx.h"


int i = 0;
int dummy = 0;
void delay(){
	dummy++;
}
void TIMER0_IRQHandler(void){
	if(i > 0){
		LPC_GPIO2 -> FIOPIN = 0xf;
        i++;
        if(i == 3)
				{
            i = 0;
				}
	}
	else{
		i++;
		LPC_GPIO2 -> FIOPIN = 0x0;
	}
	LPC_TIM0 -> IR =(1 << 0);
	delay();
}


int a,b=0;
int main(){
	LPC_TIM0 -> CTCR = 0;//Set timer mode and TC incremented when the PC maches the PR
	LPC_TIM0 -> PR = 1 ;//Set prescale 0
	LPC_TIM0 -> MR0 = 12000000; //set MR0 for 1s
	LPC_TIM0 -> TCR = 2;//Reset Timer 1
	LPC_TIM0 -> MCR = 3;//The TC will be reset if MR0 maches it and the TC and PC will be stopped
	
	NVIC_SetPriority(TIMER0_IRQn,0);
	NVIC_EnableIRQ(TIMER0_IRQn);
	LPC_GPIO2 -> FIODIR = 0xf;
	LPC_GPIO3 -> FIODIR = 1<<26;
	
	LPC_TIM0 -> TCR = 1;//Enable Timer 1	
	while(1){
	}
}