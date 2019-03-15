#include "lcd.h"
#include <stdlib.h>
void LCD_SendCommand (uint8 command)
{
	DIO_WritePort(LCD_CTRL_PORT, RS, STD_LOW);
	DIO_WritePort(LCD_CTRL_PORT, RW, STD_LOW);
	delay_ms(100);
	DIO_WritePort(LCD_CTRL_PORT, E, STD_HIGH);
	delay_ms(100);
	DIO_Write8Bits(LCD_CTRL_PORT, command);
	delay_ms(100);
	DIO_WritePort(LCD_CTRL_PORT, E, STD_LOW);
	delay_ms(100);
}

void LCD_SendData (uint8 data) 
{
/*
 LCD_CTRL_PORT = 0x01;  // setting Rs = 1 and Rw =0 
 LCD_CTRL_PORT |= 0x04; // assert enable 
 LCD_DATA_PORT = data;
 delay_ms(100);
 LCD_CTRL_PORT = 0; 
*/
}
void LCD_DisplayString (const uint8 *str)
{
	int i;
	LCD_SendCommand(Cursor_Location);
	for(i=0;str[i]!=0;i++)  
	{
		LCD_SendData (str[i]);  
	}
}

void LCD_IntegerToString (uint16 data)
{
	uint8 ArrayofChar [20]; //Array of Characters/String to Hold Ascii result
	itoa(data, ArrayofChar, 10);
	LCD_DisplayString(ArrayofChar);
}
void LCD_Init (void)
{
	//initiallizing data port and control port and setting their pins as output
	Port_Init(LCD_CTRL_PORT);
	Port_Init(LCD_DATA_PORT);
	Port_SetPinDirection(LCD_CTRL_PORT,RS,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_CTRL_PORT,RW,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_CTRL_PORT,E,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_DATA_PORT,0xFF,PORT_PIN_OUT);
	//setting lcd to operate in two lines eight bits mode
	LCD_SendCommand(TwoLineEightBitMode);
	LCD_SendCommand(Cursor_Off);
	LCD_SendCommand(Clear_Command);
}

//the implementation of itoa functions and its additional functions

void swap(uint8 *x, uint8 *y) {
	uint8 t = *x; *x = *y; *y = t;
}

// function to reverse buffer[i..j]
uint8 * reverse(uint8 *buffer, uint16 i, uint16 j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}

// Iterative function to implement itoa() function in C
uint8* itoa(int value, uint8* buffer, uint16 base)
{
	uint16 i,n;
	// invalid input
	if (base < 2 || base > 32)
		return buffer;

	// consider absolute value of number
	n=abs(value);

	i= 0;
	while (n)
	{
		uint16 r = n % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}

	// if number is 0
	if (i == 0)
		buffer[i++] = '0';

	// If base is 10 and value is negative, the resulting string 
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0'; // null terminate string

	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}



