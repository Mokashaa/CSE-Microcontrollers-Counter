#include "switch.h"

void Switch_Init_Down(uint8 port_index, uint8 pins_mask)
{
	Port_Init(port_index);
	Port_SetPinDirection(port_index,pins_mask,PORT_PIN_IN);
	Port_SetPinPullDown(port_index,pins_mask,1);
}
uint8 Switch_ReadContinously(uint8 port_index, uint8 pins_mask)
{
	
	return 0;
}
