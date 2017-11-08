/****************************************Copyright (c)****************************************************
**								   http://www.ECA.ir
**--------------File Info--------------------------------------------------------------------------------*/

#ifndef __UART_H
#define __UART_H

void UART0_Init (void);
int  UART0_SendByte (int ucData);
int  UART0_GetChar (void);
void UART0_SendString (unsigned char *s); 
void UART2_Init (void);
int  UART2_SendByte (int ucData);
int  UART2_GetChar (void);
void UART2_SendString (unsigned char *s);
void UART0_SendChar(uint16_t disp);  
void UART2_SendChar(uint16_t disp);

#endif
