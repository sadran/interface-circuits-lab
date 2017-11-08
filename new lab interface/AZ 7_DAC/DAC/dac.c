#include "LPC17xx.h"

int main(void){
	float i;
	float  i2;
	float sin;
	int temp;
	uint16_t j;
	
	LPC_PINCON->PINSEL1 = 2<<20;	/* set p0.26 to DAC output */ 
	while (1)
		{                          
			for (i =-3.14; i < 3.14; i=i+0.01)
			{	
				i2=i*i;
				sin = i*( 1+ i2*( -0.166666+i2*( 0.008333-i2*0.000198)));     //taylore
			  temp = (sin *512)+512;
				LPC_DAC->DACR = (temp << 6);
    	}
    } 
}

