#include "lpc17xx.h"
#include "delay.h"
int main()
{
	float i ;
	float i2;
	float sin;
	uint8_t upper_byte ;
	uint8_t lower_byte;
	
	
	LPC_SC->PCONP |= 1<<8;  											//ENABLE SP POWER / CLK CONTROL BIT
	LPC_PINCON->PINSEL0 |= 0xC0000000; 								//CONFIG P0.15 FOR SCK									
	LPC_PINCON->PINSEL1 |= 0x30;								//CONFIG P0.18 FOR MOSI
	LPC_SPI->SPCCR = 2; 
	LPC_SPI->SPCR = 0x20;												//SPI SENDs 16 BIT PER TRASFER ANS WORKS AS MASTER
	
	LPC_GPIO0->FIODIR = 0x1;								//SET P0.0 OUTPUT FOR CS

	while(1)
	{
		
		for(i=-3.14 ; i<3.14 ; i=i+0.01)
		{
			i2=i*i;
			sin = i*( 1+ i2*( -0.166666+i2*( 0.008333-i2*0.000198)));     //taylore
			sin = (sin * 2048)+2048;
			upper_byte = 0x60 | ( ((int)sin >> 8 ) & 0x0F );
			lower_byte = (int)sin & 0x0FF;
				
			LPC_GPIO0 -> FIOPIN = 0x00;						//ENABLE CS
			LPC_SPI->SPDR = upper_byte;
			while(!(LPC_SPI->SPSR & 0x80));				//WANTING FOT RECEIVING DATA 
			
			LPC_SPI->SPDR = lower_byte;
			while(!(LPC_SPI->SPSR & 0x80));				//WANTING FOT RECEIVING DATA 
			
			LPC_GPIO0 -> FIOSET = 0x1;						//DISABLE CS
					
		}
	}	
}

