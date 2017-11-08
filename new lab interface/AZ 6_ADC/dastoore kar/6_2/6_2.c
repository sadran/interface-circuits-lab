#include "lpc17xx.h"

#define LCD_LPC1768
#define LCD_PORT_2
#define LCD_RS 0
#define LCD_RW 1
#define LCD_E 2
#define LCD_DB4 4
#define LCD_DB5 5
#define LCD_DB6 6
#define LCD_DB7 7

#include "lcd.h"

void delay(unsigned int time)
{
while (time-- );
}

int main()
{
	uint16_t i =0;
	LPC_GPIO2->FIODIR = 0xffffffff;
	LPC_PINCON -> PINSEL1 |= 1<<14 ;          //SET P0.23 AS AD0[0]
	LPC_PINCON -> PINSEL1 |= 1<<16 ;          //SET P0.24 AS AD0[1]
	LPC_SC ->PCONP |= (1<<12);							//ENABLE POWER FOR ADC BLOCK
	
	LPC_ADC ->ADCR |= 0x0400;								//ADC CLOCK IS 25MHz / 5
	LPC_ADC ->ADCR |= (1<<21);							//power up
	
	while (1)
	{
		LPC_ADC ->ADCR |= 0x01;													//SELECT ADC0.0
		LPC_ADC -> ADCR |= (1<<24); 										// Start ADC
		while( (LPC_ADC->ADGDR & (1<<31))==0 ) ;        //WATING FOT COMPLETE CONVERSION
		i = ( (LPC_ADC ->ADDR0 )>>4 ) & 0xFFF ;
		i= i/12.41;
		lcd_clear();
		lcd_gotoxy(1,1);
		lcd_puts(i);
		LPC_ADC -> ADCR &= ~(1<<24); 										// stop ADC
		LPC_ADC ->ADCR &= ~(0x00000001);											//DISELECT ADC0.0
		
		delay(10000);
		
		LPC_ADC ->ADCR |= 0x02;													//SELECT ADC0.1
		LPC_ADC -> ADCR |= (1<<24); 										// Start ADC		
		while( (LPC_ADC->ADGDR & (1<<31))==0 ) ;        //WATING FOT COMPLETE CONVERSION
		i = ( (LPC_ADC ->ADDR1 )>>4 ) & 0xFFF ;
		lcd_gotoxy(2,1);
		lcd_puts(i);
		LPC_ADC -> ADCR &= ~(1<<24); 										// stop ADC
		LPC_ADC ->ADCR &= ~(0x00000010);											//DISELECT ADC0.1
		delay(20000000);																
	}
}



	