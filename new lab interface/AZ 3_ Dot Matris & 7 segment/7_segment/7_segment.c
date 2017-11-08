#include "lpc17xx.h"

void refresh(int data);
void delay(int time);

int main()
{
	int data;
	int temp;
	
	LPC_GPIO0->FIODIR=0xF;       //CONTROLL
	LPC_GPIO0->FIOCLR=0xF;
	LPC_GPIO2->FIODIR=0xFF;       //DATA
	LPC_GPIO2->FIOCLR=0xFF;
	
	while (1)
	{
		for(data=0 ; data<100 ; data++)
			for(temp=0 ; temp<1000 ; temp++)
				refresh(data);
		
	}
	
}
///////////////////////////////////////////////

void delay(int time)
{
	int s;
	for(s=0;s<time;s++) ;
}

//////////////////////////////////////////////
void refresh(int data)
{
	int c;
	int converter[] = {0x3F , 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	
	for(c=1 ; c==1 || c==2 ; c++)
	{	
	LPC_GPIO0->FIOCLR = 0xF;
	LPC_GPIO2->FIOCLR = 0xFF;
	
	if(c==1)
		LPC_GPIO2->FIOSET = converter[data%10];
	if(c==2)
		LPC_GPIO2->FIOSET = converter[data/10];
	
	LPC_GPIO0->FIOSET = c;
	delay(5000);
	} 
	
	
}



	