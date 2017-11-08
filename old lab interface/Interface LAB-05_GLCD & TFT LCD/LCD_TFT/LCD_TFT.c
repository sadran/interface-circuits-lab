#include <lpc17xx.h>
#define family_lpc17xx
#define TFTLCD_DATAPORT_1
#define TFTLCD_DATAPORT_OFFSET 15
#define TFTLCD_CONTROLPORT_0
#define TFTLCD_RST 26
#define TFTLCD_RS 23
#define TFTLCD_CS 22
#define TFTLCD_RD 25
#define TFTLCD_WR 24
#define PORTRAIT
#include "tftlcd_functions.h"

int main(){
    SystemInit();
    tftlcd_init();
    tftlcd_clear();
    tftlcd_fill(0x0000ff);
    wait_ms(4000);
    tftlcd_draw_circle(120,160,30,1,0xdbc311);
    while(1);
}