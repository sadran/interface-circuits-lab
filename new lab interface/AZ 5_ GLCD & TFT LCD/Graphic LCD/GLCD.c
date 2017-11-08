#include "lpc17xx.h"

#define GLCD_LPC17xx
#define GLCD_DATAPORT_2
#define GLCD_CONTROLPORT_0
#define GLCD_EN 4
#define GLCD_RW 5
#define GLCD_RS 6
#define GLCD_CS1 0
#define GLCD_CS2 1
#define GLCD_RST 2
#define GLCD_D0 0

#include "ks0108.h"

int main()
{
	SystemInit();
	GLCD_Initialize();
	GLCD_ClearScreen();
	GLCD_GoTo(53,11);
	GLCD_WriteString("ARM");
	GLCD_Circle(63,27,20);
		while(1){}
	
}

