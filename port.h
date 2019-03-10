#ifndef PORT_H_
#define PORT_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"

typedef enum 
{
	PORT_PIN_IN = 0,
	PORT_PIN_OUT = 1
}Port_PinDirectionType;

void Port_Init (uint8 port_index);
void Port_SetPinDirection (uint8 port_index, uint8 pins_mask, Port_PinDirectionType direction);
void Port_SetPinPullUp (uint8 port_index, uint8 pins_mask, uint8 enable);
void Port_SetPinPullDown (uint8 port_index, uint8 pins_mask, uint8 enable);

#endif
