#include "lpc17xx.h"

int main()
{
	LPC_GPIO0 -> FIODIR = 0xF;
	LPC_GPIO0 -> FIOCLR = 0xF;
	
	while (1)
	{
		if ( (LPC_GPIO0->FIOPIN & 1<<4) == 0 )
		{
			LPC_GPIO0 -> FIOSET = 0x1;
		}
		else
		{
			LPC_GPIO0 -> FIOCLR = 0x1;
		}
////////////////////////////////////////////
		if ( (LPC_GPIO0->FIOPIN & (2<<4)) == 0 )
		{
			LPC_GPIO0 -> FIOSET = 0x2;
		}
		else
		{
			LPC_GPIO0 -> FIOCLR = 0x2;
		}
//////////////////////////////////////////
		if ( (LPC_GPIO0->FIOPIN & (4<<4)) == 0 )
		{
			LPC_GPIO0 -> FIOSET = 0x4;
		}
		else
		{
			LPC_GPIO0 -> FIOCLR = 0x4;
		}
//////////////////////////////////////////
		if ( (LPC_GPIO0->FIOPIN & 8<<4) == 0 )
		{
			LPC_GPIO0 -> FIOSET = 0x8;
		}
		else
		{
			LPC_GPIO0 -> FIOCLR = 0x8;
		}
	}
}


