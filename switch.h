#ifndef SWITCH_H_
#define SWITCH_H_

#include "port.h"
#include "DIO.h"

// This function is used to initialize the switch; by initializing a port for it and declaring its bit as I/p
void Switch_Init(uint8 port_index, uint8 pins_mask);
// This function reads whether the switch is pressed or not
uint8 Switch_Read(uint8 port_index, uint8 pins_mask);


#endif
