#include "LPC17xx.h"

void delay (int i){
while(i--);
}

int main(void){
LPC_GPIO2->FIODIR = 0XFFFFFFFF;
LPC_GPIO0->FIODIR = 0XFFFFFFFF;
LPC_GPIO1->FIODIR = 0X00000000;
 	while(1){
 		if((LPC_GPIO1->FIOPIN & (1<<0))==0){
 		LPC_GPIO2->FIOPIN = 0XBF;
 			LPC_GPIO0->FIOPIN = 0X88;
 			delay(400000);
 		}
 		else {
 			LPC_GPIO2->FIOPIN = 0XCF;
 			LPC_GPIO0->FIOPIN =0X88;
 			delay(400000);
 		}
 	}
}
