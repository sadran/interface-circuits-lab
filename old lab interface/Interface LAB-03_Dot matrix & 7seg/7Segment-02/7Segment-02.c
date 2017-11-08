#include "lpc17xx.h"
unsigned char digit[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0xF};

void Delay (unsigned int Time)
{
unsigned int i = 0;
    while (Time--){
        for (i = 0 ; i<5000 ; i++);
    }
}
int i,j,y;
int main(){
	LPC_GPIO0->FIODIR = 0xFFFFFFFF;
LPC_GPIO2->FIODIR = 0xFFFFFFFF;
	while(1){
Delay(250);
		for(i=0;i<=9;i++){
			for(j=0;j<=9;j++){
				for(y=0;y<=100;y++){			
					LPC_GPIO0->FIOPIN = 1;
					LPC_GPIO2->FIOPIN = digit[j];	
					Delay(10);
					LPC_GPIO0->FIOPIN = 2;
					LPC_GPIO2->FIOPIN = digit[i];
					Delay(10);
					}
			}
		}
	}
}

