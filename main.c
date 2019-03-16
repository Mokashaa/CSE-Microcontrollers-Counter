#include "lcd.h"
#include "switch.h"

void SystemInit() {
	

	/* Switches Initiallization with pull down resistors  */ 
	//increment switch on PB0
	//decrement switch on PB1
	//reset switch on PB2
	Switch_Init_Down(PB, 0xE0);
	
	/*  LCD Initialization */
	LCD_Init();
	LCD_IntegerToString(0);
}
	
int main(void){

while(1)
{
	Switch_HandleOnLevel(PA, 0x20); //increment
	Switch_HandleOnRelease(PA, 0x40); //reset
	Switch_HandleOnPress(PA, 0x80); //decrement
	

	
	
} 
}
