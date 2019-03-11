#include "port.h"

void Port_Init (uint8 port_index)
{
	SYSCTL_RCGCGPIO_R |= (1 << port_index);
	switch(port_index)
	{
		case PA:
		{
			GPIO_PORTA_LOCK_R = 0x4C4F434B;
			GPIO_PORTA_CR_R = 0xFF;
			GPIO_PORTA_DEN_R = 0xFF;
			break;
		}

		case PB:
		{
			GPIO_PORTB_LOCK_R = 0x4C4F434B;
			GPIO_PORTB_CR_R = 0xFF;
			GPIO_PORTB_DEN_R = 0xFF;
			break;
		}

		case PC:
		{
			GPIO_PORTC_LOCK_R = 0x4C4F434B;
			GPIO_PORTC_CR_R = 0xFF;
			GPIO_PORTC_DEN_R = 0xFF;
			break;
		}
		
		case PD:
		{
			GPIO_PORTD_LOCK_R = 0x4C4F434B;
			GPIO_PORTD_CR_R = 0xFF;
			GPIO_PORTD_DEN_R = 0xFF;
			break;
		}
		
		case PE:
		{
			GPIO_PORTE_LOCK_R = 0x4C4F434B;
			GPIO_PORTE_CR_R = 0xFF;
			GPIO_PORTE_DEN_R = 0xFF;
			break;
		}
		
		case PF:
		{
			GPIO_PORTF_LOCK_R = 0x4C4F434B;
			GPIO_PORTF_CR_R = 0xFF;
			GPIO_PORTF_DEN_R = 0xFF;
			break;
		}		
	}
}
	
void Port_SetPinPullDown(uint8 port_index,uint8 pins_mask,uint8 enable)
{
	switch(port_index)
	{
		case 'PA':
			if (enable){GPIO_PORTA_PDR_R |= pins_mask;}
			else {GPIO_PORTA_PDR_R &= ~pins_mask;}
			break;
		case 'PB':
			if (enable){GPIO_PORTB_PDR_R |= pins_mask;}
			else {GPIO_PORTB_PDR_R &= ~pins_mask;}
			break;
		case 'PC':
			if (enable){GPIO_PORTC_PDR_R |= pins_mask;}
			else {GPIO_PORTC_PDR_R &= ~pins_mask;}
			break;
		case 'PD':
			if (enable){GPIO_PORTD_PDR_R |= pins_mask;}
			else {GPIO_PORTD_PDR_R &= ~pins_mask;}
			break;
		case 'PE':
			if (enable){GPIO_PORTE_PDR_R |= pins_mask;}
			else {GPIO_PORTE_PDR_R &= ~pins_mask;}
			break;
		case 'PF':
			if (enable){GPIO_PORTF_PDR_R |= pins_mask;}
			else {GPIO_PORTF_PDR_R &= ~pins_mask;}
			break;
	}
}

	
