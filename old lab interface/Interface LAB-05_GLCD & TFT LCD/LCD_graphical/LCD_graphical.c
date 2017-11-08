#include <LPC17xx.h>
#define GLCD_LPC17xx
#define GLCD_DATAPORT_2
#define GLCD_CONTROLPORT_0
#define GLCD_RS 4
#define GLCD_RW 5
#define GLCD_EN 6
#define GLCD_CS1 7
#define GLCD_CS2 8
#define GLCD_CS3 9
#define GLCD_D0 0
#include "ks0108.h"

int main(){
    SystemInit();
    GLCD_Initialize();
    GLCD_ClearScreen();
    GLCD_Line(50,20,60,30);
    GLCD_Rectangle(10,15,15,15);
    GLCD_Circle(110,25,8);
    GLCD_GoTo(25,5);
    GLCD_WriteString("ARM laboratory");
    while(1);
}
