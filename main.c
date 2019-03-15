#include "lcd.h"
#include "switch.h"

void Delay100ms(int x)
{
unsigned long i;
i = 1333333*x; 
while(i > 0)
i = i - 1;
}

void SystemInit() {
	Port_Init(PF);
	Port_SetPinDirection(PF, 0x04, PORT_PIN_OUT);
	Port_SetPinPullUp(PF, 0x04, 1);
  GPIO_PORTF_DATA_R |= 0x04;	
}
	
int main(void){ unsigned long volatile delay;

while(1)
{
DIO_WritePort(PF, 0x04, STD_LOW);

Delay100ms(2); // delay for 100m

	
DIO_WritePort(PF, 0x04, STD_HIGH);
	
Delay100ms(2); // delay for 100ms


} 
}
