#include "lpc17xx.h"
#include <stdio.h>
#include "uart.h"

void delay(int i )
{
	while(1) i--;
}

int main()
{
	char i;
	SystemInit();
	UART0_Init();
	UART0_SendString("sadra nasiri");
	UART0_SendString("/r/n");
	while(1)
	{	
	UART0_SendString("your character is :");
	i=UART0_GetChar();
	UART0_SendByte((char)i);
	UART0_SendString("/r/n");
	}
}

