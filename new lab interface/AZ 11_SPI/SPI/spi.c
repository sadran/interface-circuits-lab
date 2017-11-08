
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
#include "delay.h"

int main()
{
	int data = 0;
	
	LPC_SC->PCONP |= 1<<8; 									//ENABLE SPI POWER / CLOCK CONTROL BIT
		
	LPC_PINCON->PINSEL0 |= 0xC0000000; 					//SELECT P0.15 AS SCK
	LPC_PINCON->PINSEL1 |= 0x3c;		  					//SELECT P0.17 ASS MISO AND P0.18 AS MOSI
	
	LPC_SPI->SPCCR = 2 ; 										//DIVIDE PCLOCL/2 FOR SPI
	LPC_SPI->SPCR = 0x20; 									//SPI SEND & RECIVE DATA IN 12 BIT AND WORKS AS MASTER
	
	LPC_GPIO0->FIODIR = 0x1;								//SET P0.0 OUTPUT FOR CS

	lcd_init();
	lcd_clear();
	
while(1)
{
	LPC_GPIO0 -> FIOPIN = 0x00;						//ENABLE CS
	
	LPC_SPI->SPDR = 0x01;
	while(!(LPC_SPI->SPSR & 0x80));				//WANTING FOT RECEIVING DATA 
	
	LPC_SPI->SPDR=0xA0;
	while(!(LPC_SPI->SPSR & 0x80));				//WANTING FOT RECEIVING DATA 
	data = (LPC_SPI->SPDR & 0x0F) << 8;
	
	LPC_SPI->SPDR=0x00;
	while(!(LPC_SPI->SPSR & 0x80));				//WANTING FOT RECEIVING DATA 
	//data = data<<8;
	data |= (LPC_SPI->SPDR & 0xFF);
	LPC_GPIO0 -> FIOSET = 0x1;						//DISABLE CS
	
	delay_ms(1000); 
	lcd_clear();
	lcd_puts((data));
	
	
}	
}


