#include<lpc17xx.h>

unsigned short ADC_Read(void)
{
 	unsigned int i;	
	LPC_PINCON -> PINSEL1 = 0x00004000; // p0.23 select as ADC0.0
 	LPC_SC->PCONP |= (1 << 12);                 // Enable power to AD block 
 	LPC_ADC->ADCR |= 0x01;                    //select AD0.0 
	LPC_ADC->ADCR |= 0x0100;     	     //ADCLK is 12.5 MHz
 	LPC_ADC->ADCR |= 0x200000;   	     //Power up,1 << 21	                            
	LPC_ADC->ADCR |= 0x01000000;	    // Start A/D Conversion
 	while ((LPC_ADC->ADGDR & 0x80000000) == 0); // Wait for end of 	A/D Conversion
	i = LPC_ADC->ADDR0; 			     // Read A/D Data Register
 	return (i >> 4) & 0x0FFF;		    // bit 4:15 is 12 bit AD value
}
int main(){
	LPC_GPIO0 -> FIODIR = 0xFFFFFFFF;
	while(1){
		LPC_GPIO0 -> FIOPIN = ADC_Read();
	}
	return 0;
}