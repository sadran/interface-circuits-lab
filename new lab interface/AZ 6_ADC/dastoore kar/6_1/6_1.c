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
	LPC_GPIO0->FIODIR = 0xFF;
	LPC_PINCON -> PINSEL1 = 1<<14 ;          //SET P0.23 AS ADC
	LPC_SC ->PCONP |= (1<<12);							//ENABLE POWER FOR ADC BLOCK
	LPC_ADC ->ADCR |= 0x01;									//SELECT ADC0.0
	LPC_ADC ->ADCR |= 0x0400;								//ADC CLOCK IS 25MHz / 5
	LPC_ADC ->ADCR |= (1<<21);
	
	while (1)
	{
		LPC_ADC -> ADCR |= (1<<24); 										// Start ADC
		while( (LPC_ADC->ADGDR & (1<<31))==0 ) ;        //WATING FOT COMPLETE CONVERSION
		i = ( (LPC_ADC ->ADDR0 )>>4 ) & 0xFFF ;
		lcd_clear();
		lcd_gotoxy(1,1);
		lcd_puts(i);
		
		if(i<400)
			{LPC_GPIO0->FIOPIN = 0xFF;}
		else {if(400<i && i<800)	LPC_GPIO0->FIOPIN = 0xFC;
					else {if (800<i && i<1200) LPC_GPIO0->FIOPIN = 0xFE;
								else {if (1200<i && i<1600) LPC_GPIO0->FIOPIN = 0xF8;
											else {if (1600<i && i<2000) LPC_GPIO0->FIOPIN = 0xF0;
														else {if(2000<i && i<2400)	LPC_GPIO0->FIOPIN = 0xE0;
																	else {if (2400<i && i<2800) LPC_GPIO0->FIOPIN = 0xC0;
																				else {if (2800<i && i<3200) LPC_GPIO0->FIOPIN = 0x80;
																							else {if (3200<i) LPC_GPIO0->FIOPIN = 0x00;												
																									 }
																						 }
																			 }
																 }
													 }
										 }
							 }
				}	
		delay(20000000);																
		LPC_GPIO0->FIOCLR= 0xFF;
	}
}


	