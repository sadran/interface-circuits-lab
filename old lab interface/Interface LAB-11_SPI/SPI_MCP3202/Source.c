#include <lpc17xx.h>

int main(void){
	int data = 0;
	LPC_SC -> PCONP |= (1 << 8); //Enable SPI power/clock control bit
	LPC_PINCON -> PINSEL0 |= 0xC0000000; //Enable P0.15 for SCK
	LPC_PINCON -> PINSEL1 |= 0x0000003C; //Enable P0.17 for MISO and P0.18 for MOSI
	LPC_SPI -> SPCCR = 2; //Divide Pclock/2 for SPI
	LPC_SPI -> SPCR = 0x20; //SPI send & receive 8 bit per transfer and SPI work as Master
	
	LPC_GPIO0 -> FIODIR0 = 0x01; //Set P0.0 output for CS
	LPC_GPIO2 -> FIODIRL = 0XFFFF; //Set P2.0 - P2.11 output for LEDs
	
	while(1){
		LPC_GPIO0 -> FIOPIN0 = 0x00; //Enable CS
		
		LPC_SPI -> SPDR = 0x01;
		while(!(LPC_SPI -> SPSR & 0x80)); //Wait for send data
		
		LPC_SPI -> SPDR = 0xA0;
		while(!(LPC_SPI -> SPSR & 0x80)); //Wait for send data
		data = LPC_SPI -> SPDR;
		LPC_SPI -> SPDR = 0x00;
		while(!(LPC_SPI -> SPSR & 0x80)); //Wait for send data
		data = data << 8;
		data |= LPC_SPI -> SPDR;
		
		LPC_GPIO0 -> FIOPIN0 = 0x01;//Disable CS
		LPC_GPIO2 -> FIOPINL = data;
		data--;
		data--;
	}
}

