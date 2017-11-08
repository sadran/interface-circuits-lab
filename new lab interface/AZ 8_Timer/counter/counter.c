#include "lpc17xx.h"
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

void delay(){
	int i =0;
	for(i=0;i<5000000 ; i++);
}


int main(){
	LPC_TIM1 -> CTCR = 1;//Set Counter mode and rising edges on the CAP
	LPC_TIM1 -> PR = 0 ;//Set prescale 0
	LPC_TIM1 -> MR0 = 0XFFF; 
	LPC_TIM1 -> TCR = 2;//Reset Counter 1
	LPC_TIM1 -> MCR = 3;//The TC will be reset if MR0 maches it and the TC and PC will be stopped
	LPC_PINCON -> PINSEL3 = 0x00000030;//Set for CAP1.0
	LPC_GPIO2 -> FIODIR = 0xff;
	LPC_TIM1 -> TCR = 1;//Enable Counter 1
		
	lcd_gotoxy(1,0);
	lcd_clear();
	
	
	while(1){
		lcd_puts(LPC_TIM1->TC);
		delay();
		lcd_clear();
		
	}
}