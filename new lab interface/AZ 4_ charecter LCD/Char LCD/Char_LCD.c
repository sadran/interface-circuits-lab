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

int main(){
	LPC_GPIO2 -> FIODIR = 0XFFFFFFFF;
	lcd_init();
	lcd_clear();
	//delay(100000);
	lcd_gotoxy(1,1);
	lcd_putsf("ARM");
	lcd_gotoxy(2,1);
	lcd_putsf("Micro Controller");
	
	while(1){
		
	}
}

