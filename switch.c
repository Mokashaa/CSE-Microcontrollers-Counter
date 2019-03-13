#include "switch.h"
//#include "counter.h"


uint8 OnPress_flag =0;

void Switch_Init_Down(uint8 port_index, uint8 pins_mask)
{
	Port_Init(port_index);
	Port_SetPinDirection(port_index,pins_mask,PORT_PIN_IN);
	Port_SetPinPullDown(port_index,pins_mask,1);
}
void Switch_Init_Up(uint8 port_index, uint8 pins_mask)
{
	Port_Init(port_index);
	Port_SetPinDirection(port_index,pins_mask,PORT_PIN_IN);
	Port_SetPinPullUp(port_index,pins_mask,1);
}
void Switch_HandleOnLevel(uint8 port_index, uint8 pins_mask)
{
	
}


void Switch_HandleOnPress(uint8 port_index, uint8 pins_mask)
{
	
}

void Switch_HandleOnRelease(uint8 port_index, uint8 pins_mask)
{

}

