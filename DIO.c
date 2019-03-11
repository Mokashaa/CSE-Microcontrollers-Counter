#include "DIO.h" 
uint8 DIO_ReadPort (uint8 port_index, uint8 pins_mask)
{
	switch(port_index)
	{
	case 'PA':
		return (GPIO_PORTA_DATA_R & pins_mask);
	break;
	case 'PB':
	return (GPIO_PORTB_DATA_R & pins_mask);
	break;
	case 'PC':
	return (GPIO_PORTC_DATA_R & pins_mask);
	break;
	case 'PD':
	return (GPIO_PORTD_DATA_R & pins_mask);
	break;
	case 'PE':
	return (GPIO_PORTE_DATA_R & pins_mask);
	break;
	case 'PF':
	return (GPIO_PORTF_DATA_R & pins_mask);
	break;
	}
}