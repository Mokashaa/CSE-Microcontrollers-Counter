#include "lcd.h"
#include "switch.h"

void SystemInit() {
	
	//LCD is connected to PORT A
	Port_Init(PA);
	Port_SetPinDirection(PA, 0xFF, PORT_PIN_OUT);
	Port_SetPinPullUp(PA, 0x04, 1);
	
	//increment switch on PB0
	//decrement switch on PB1
	//reset switch on PB2
	Switch_Init_Down(PB, 0x07);
	
	//LCD Initialization
	LCD_Init();
	
}
	
int main(void){

while(1)
{
	Switch_HandleOnLevel(PB, 0x01); //increment
	Switch_HandleOnRelease(PB, 0x02); //reset
	Switch_HandleOnPress(PB, 0x04); //decrement
} 
}
