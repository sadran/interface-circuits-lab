#include <LPC17xx.h>
#include <stdio.h>
#include "uart.h"
void Delay (uint32_t Time){
    uint32_t i;
    i = 0;
    while (Time--) {
        for (i = 0; i < 5000; i++);
    }
}
int main(void){
	int i;
	SystemInit();
	UART0_Init();
	UART0_SendString("\r\n\MyName Family\r\n\n");
	while(1){
		UART0_SendString("your character= ");
		i=UART0_GetChar();
		UART0_SendByte((char) i);
		UART0_SendString("\r\n");
	}
}
