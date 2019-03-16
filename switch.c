#include "switch.h"
#include "Application.h"

void Switch_Init_Down(uint8 port_index, uint8 pins_mask)
{
	Port_Init(port_index);
	Port_SetPinDirection(port_index,pins_mask,PORT_PIN_IN);
	Port_SetPinPullDown(port_index,pins_mask,1);
}

/*void Switch_Init_Up(uint8 port_index, uint8 pins_mask)
{
	Port_Init(port_index);
	Port_SetPinDirection(port_index,pins_mask,PORT_PIN_IN);
	Port_SetPinPullUp(port_index,pins_mask,1);
}*/

void Switch_HandleOnLevel(uint8 port_index, uint8 pins_mask)
{
	if(DIO_ReadPort(port_index,pins_mask))
	{
		Delay100ms(0.0055); // de-bouncing
		if(DIO_ReadPort(port_index,pins_mask))
		{
			while(DIO_ReadPort(port_index,pins_mask)) 	
				{
					 increment();
					 Delay100ms(0.0325);  //consider the delay in lcd_command and lcd_data }
				}
				
		}	
	}
}


void Switch_HandleOnPress(uint8 port_index, uint8 pins_mask)
{
		if(DIO_ReadPort(port_index,pins_mask))
		{
			Delay100ms(0.0055);
			//second check due to switch de-bouncing
			if(DIO_ReadPort(port_index,pins_mask))
			{
				decrement();
				while(DIO_ReadPort(port_index,pins_mask)) {}
			}
		}
}

void Switch_HandleOnRelease(uint8 port_index, uint8 pins_mask)
{
	if(DIO_ReadPort(port_index,pins_mask))
	{
		Delay100ms(0.0055);
		if(DIO_ReadPort(port_index,pins_mask))
		{
			while(DIO_ReadPort(port_index,pins_mask)) {}
			reset();
		}
	}
}

