#include <LPC17xx.h>
void delay(int i){ 
 	while(i--); 
} 
int main(void){ 
LPC_GPIO2->FIODIR0 = 0XFF; 
 	LPC_GPIO0->FIODIR0 = 0XFF; 
 	while(1){ 
  		LPC_GPIO0->FIOPIN0 = 0x01; 
  		LPC_GPIO2->FIOPIN0 = 0X00; 
  		delay(5000); 
  		LPC_GPIO0->FIOPIN0 = 0x02; 
		LPC_GPIO2->FIOPIN0 = 0Xc6; 
  		delay(5000); 
  		LPC_GPIO0->FIOPIN0 = 0x04; 
  		LPC_GPIO2->FIOPIN0 = 0Xe3; 
 		delay(5000); 
  		LPC_GPIO0->FIOPIN0 = 0X08; 
  		LPC_GPIO2->FIOPIN0 = 0Xb1; 
  		delay(5000); 
  		LPC_GPIO0->FIOPIN0 = 0X10; 
  		LPC_GPIO2->FIOPIN0 = 0Xb1; 
  		delay(5000); 
  		LPC_GPIO0->FIOPIN0 = 0X20; 
  		LPC_GPIO2->FIOPIN0 = 0X9b; 
  		delay(5000); 
  		LPC_GPIO0->FIOPIN0 = 0X40; 
  		LPC_GPIO2->FIOPIN0 = 0X8e; 
  		delay(5000); 
  		LPC_GPIO0->FIOPIN0 = 0X80; 
  		LPC_GPIO2->FIOPIN0 = 0X00; 
  		delay(5000); 
}
}
