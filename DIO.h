#ifndef DIO_H_
#define DIO_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"

typedef enum 
{
	STD_LOW = 0,
	STD_HIGH = 1
}DIO_LevelType;

uint8 DIO_ReadPort (uint8 port_index, uint8 pins_mask);
void DIO_WritePort (uint8 port_index, uint8 pins_mask, DIO_LevelType pins_level);
void DIO_FlipPort (uint8 port_index, uint8 pins_mask);
void DIO_Write8Bits (uint8 port_index, uint8 pins_mask);
//Delay Function
void delay_ms (uint32_t x);
#endif
