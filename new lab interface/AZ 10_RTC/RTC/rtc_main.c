#include "lpc17xx.h"
#include "rtc.h"
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
#include "delay.h"
RTCTime local_time, current_time;

int main(){
	lcd_init();
	lcd_clear();
	RTCInit();
	local_time.RTC_Sec = 00;		/* Second value - [0,59] */
	local_time.RTC_Min = 22;		/* Minute value - [0,59] */
	local_time.RTC_Hour = 21;		/* Hour value - [0,23] */
	local_time.RTC_Mday = 4;		/* Day of the month value - [1,31] */
	local_time.RTC_Wday = 0;		/* Day of week value - [0,6] */
	local_time.RTC_Yday = 0;		/* Day of year value - [1,365] */
	local_time.RTC_Mon = 8;			/* Month value - [1,12] */
	local_time.RTC_Year = 1396;	/* Year value - [0,4095] */
	RTCSetTime(local_time);
	RTCStart();
	
	while(1){
		current_time = RTCGetTime();
		lcd_gotoxy(1,1);
		lcd_puts(current_time.RTC_Year);
		lcd_putchar('/');
		lcd_puts(current_time.RTC_Mon);
		lcd_putchar('/');
		lcd_puts(current_time.RTC_Mday);
		lcd_gotoxy(2,1);
		lcd_puts(current_time.RTC_Hour);
		lcd_putchar(':');
		lcd_puts(current_time.RTC_Min);
		lcd_putchar(':');
		lcd_puts(current_time.RTC_Sec);
		delay_ms(1000);
		lcd_clear();
	}
}

