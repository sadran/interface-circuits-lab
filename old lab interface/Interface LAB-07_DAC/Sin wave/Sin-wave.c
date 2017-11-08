#include "LPC17xx.h"
volatile uint16_t GusSinTable[45] =                                                             
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};
int main(void){
	uint8_t i;
	LPC_PINCON->PINSEL1 = 2<<20;	/* set p0.26 to DAC output */ 	while (1) {
     		for (i = 0; i < 45; i++){	
    	    		LPC_DAC->DACR = (GusSinTable[i] << 6);                              
    		}
    } 
}

