#include "lpc17xx.h"
#include "i2c.h"
extern  uint8_t buf[32];
void Delay(uint32_t delaydata){
    uint32_t i,j,k;
    for(i=0;i<delaydata;i++)
        for(j=0;j<1000;j++)
            for(k=0;k<100;k++);
}
int main (void){
    uint32_t i;
    SystemInit();
    LPC_GPIO2->FIODIR    = 0x000000ff;      //LEDs PORT2 are Output
    LPC_GPIO0->FIODIR   |= 0x03f80000;
    LPC_GPIO0->FIOSET    = 0x03f80000;
    if ( I2CInit( (uint32_t)I2CMASTER ) == 0 ){	//initialize I2c
        while ( 1 );						//Fatal error
    }
    for ( i = 0; i < 8; i++ ){			//clear buffer
        buf[i]=i+1;
    }
    I2C_WriteNByte(0xa0, 1, 0x00, buf, 8);//write buf array ito 	EEPROM
    Delay(50);						
    for ( i = 0; i < 8; i++ ){	       //clear buffer
        buf[i] =0;
    }
    I2C_ReadNByte (0xa0, 1, 0x00, buf, 8); //read from EEPROM & save in buff array
    Delay(50);						
    while(1){
        for(i=0;i<8;i++){
            LPC_GPIO2->FIOPIN = buf[i];
            Delay(300);
        }  
    }
}
