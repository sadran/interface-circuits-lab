/****************************************Copyright (c)****************************************************
**								   http://www.ECA.ir
**-------------------------------------------------------------------------------------------------------*/

#include "lpc17xx.h"                              /* LPC17xx definitions    */
#include "uart.h"

#define FOSC                        12000000                           

#define FCCLK                      (FOSC  * 8)                        
                                                                        
#define FCCO                       (FCCLK * 3)                          
                                                                       
#define FPCLK                      (FCCLK / 4)                          
                                                                        

#define UART0_BPS     9600                                             
#define UART2_BPS     9600                                             
/*********************************************************************************************************
** Function name:       UART0_Init

*********************************************************************************************************/
void UART0_Init (void)
{
	uint16_t usFdiv;
    /* UART0 */
    LPC_PINCON->PINSEL0 |= (1 << 4);             /* Pin P0.2 used as TXD0 (Com0) */
    LPC_PINCON->PINSEL0 |= (1 << 6);             /* Pin P0.3 used as RXD0 (Com0) */
  
  	LPC_UART0->LCR  = 0x83;                   
    usFdiv = (FPCLK / 16) / UART0_BPS;          
    LPC_UART0->DLM  = usFdiv / 256;
    LPC_UART0->DLL  = usFdiv % 256; 
    LPC_UART0->LCR  = 0x03;                    
    LPC_UART0->FCR  = 0x06; 				   
}

/*********************************************************************************************************
** Function name:       UART0_SendByte

*********************************************************************************************************/
int UART0_SendByte (int ucData)
{
	while (!(LPC_UART0->LSR & 0x20));
    return (LPC_UART0->THR = ucData);
}

/*----------------------------------------------------------------------------
  Read character from Serial Port   (blocking read)
 *----------------------------------------------------------------------------*/
int UART0_GetChar (void) 
{
  	while (!(LPC_UART0->LSR & 0x01));
  	return (LPC_UART0->RBR);
}

/*********************************************************************************************************
Write character to Serial Port
** Function name:       UART0_SendString

*********************************************************************************************************/
void UART0_SendString (unsigned char *s) 
{
  	while (*s != 0) 
	{
   		UART0_SendByte(*s++);
	}
}

/*********************************************************************************************************
** Function name:       UART2_Init

*********************************************************************************************************/
void UART2_Init (void)
{
	uint16_t usFdiv;
    /* UART2 */
    LPC_PINCON->PINSEL0 |= (1 << 20);             /* Pin P0.10 used as TXD2 (Com2) */
    LPC_PINCON->PINSEL0 |= (1 << 22);             /* Pin P0.11 used as RXD2 (Com2) */

   	LPC_SC->PCONP = LPC_SC->PCONP|(1<<24);	      

    LPC_UART2->LCR  = 0x83;                     
    usFdiv = (FPCLK / 16) / UART2_BPS;            
    LPC_UART2->DLM  = usFdiv / 256;
    LPC_UART2->DLL  = usFdiv % 256; 
    LPC_UART2->LCR  = 0x03;                       
    LPC_UART2->FCR  = 0x06;
}

/*********************************************************************************************************
** Function name:       UART2_SendByte
** Descriptions:        从串口2发送数据
** input parameters:    data: 发送的数据
** output parameters:   无
** Returned value:      无
*********************************************************************************************************/
int UART2_SendByte (int ucData)
{
	while (!(LPC_UART2->LSR & 0x20));
    return (LPC_UART2->THR = ucData);
}

/*----------------------------------------------------------------------------
  Read character from Serial Port   (blocking read)
 *----------------------------------------------------------------------------*/
int UART2_GetChar (void) 
{
  	while (!(LPC_UART2->LSR & 0x01));
  	return (LPC_UART2->RBR);
}

/*********************************************************************************************************
** Write character to Serial Port
** Function name:       UART2_SendString
** Descriptions:	    向串口发送字符串
** input parameters:    s:   要发送的字符串指针
** output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void UART2_SendString (unsigned char *s) 
{
  	while (*s != 0) 
	{
   		UART2_SendByte(*s++);
	}
}

void UART0_SendChar(uint16_t disp)
{
	uint16_t dispbuf[4];
	uint8_t i;

	dispbuf[3] = disp%10 + '0';
	dispbuf[2] = disp/10%10 + '0';
	dispbuf[1] = disp/10/10%10 + '0';
	dispbuf[0] = disp/10/10/10%10 + '0';
	for(i=0;i<4;i++)
		UART0_SendByte(dispbuf[i]);	
}

void UART2_SendChar(uint16_t disp)
{
	uint16_t dispbuf[4];
	uint8_t i;

	dispbuf[3] = disp%10 + '0';
	dispbuf[2] = disp/10%10 + '0';
	dispbuf[1] = disp/10/10%10 + '0';
	dispbuf[0] = disp/10/10/10%10 + '0';
	for(i=0;i<4;i++)
		UART2_SendByte(dispbuf[i]);	
}
