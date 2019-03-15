#include "lcd.h"
#include "switch.h"

void SystemInit() {}
	
int main ()
{
	Port_Init(PF);
	Port_SetPinDirection(PF, 0x04, PORT_PIN_OUT);
	while (1)
	{
		DIO_WritePort(PF, 0x04, STD_HIGH);
		delay_ms(5000);
	}
}

