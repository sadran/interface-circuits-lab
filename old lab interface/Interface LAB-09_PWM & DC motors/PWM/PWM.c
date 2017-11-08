#include <lpc17xx.h>

int main(){
	LPC_PINCON -> PINSEL3 = 2 << 4; //Set P1.18 for PWM1.
	LPC_PWM1 -> TCR = 0x02;//Reset timer counter for PWM.
	LPC_PWM1 -> MCR = 0x02;//The PWMC will be reset if PWMR0 matches it.
	LPC_PWM1 ->  PCR = (1<<9);//The PWM1 output enable.
	LPC_PWM1 -> MR0 = 25000;
	LPC_PWM1 -> MR1 = 17500;
	LPC_PWM1 -> TCR = 0x01;//Enable timer counter for PWM.
	while(1){
	}
}