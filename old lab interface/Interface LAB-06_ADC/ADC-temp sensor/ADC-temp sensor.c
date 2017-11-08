#include <lpc17xx.h>
#define LCD_LPC1768
#define LCD_PORT_2 
#define LCD_RS     0
#define LCD_RW     1
#define LCD_E      2
#define LCD_DB4    4
#define LCD_DB5    5
#define LCD_DB6    6
#define LCD_DB7    7
#include "lcd.h"
void delay(int w){
	while(w--);
}
int main(){
	int i = 0;
	LPC_GPIO2 -> FIODIR = 0xffffffff; 
	LPC_PINCON -> PINSEL1 = 1<<14;   	// Select P23.0 as ADC
	LPC_SC -> PCONP |= (1<<12);		// Enable power to AD block
	LPC_ADC -> ADCR |= 0x01;		// Select ADC0.0
	LPC_ADC -> ADCR |= 0x0400;		// ADC Clock is 25MHz / 5
	LPC_ADC -> ADCR |= 0x200000;	// Power up,1 << 21
	while(1){
		LPC_ADC -> ADCR |= (0<<24); // Stop ADC
		LPC_ADC -> ADCR |= (1<<24); // Start ADC
		while((LPC_ADC -> ADGDR & 0x80000000) == 0); // Wait for 		end of A/D Conversion
		i = (LPC_ADC -> ADGDR & 0xfff0);
		i = i / 12.41; //(3.3V / 2^12)=0.0806 mV   10mV / 0.0806 		= 12.41 unit
		lcd_clear();
		lcd_gotoxy(1,1);
		lcd_puts(i);
		delay(2000000);
	}
}


