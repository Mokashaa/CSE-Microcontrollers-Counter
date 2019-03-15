#include "lcd.h"

void LCD_SendCommand (uint8 command)
{
	DIO_WritePort(LCD_CTRL_PORT, RS, STD_LOW);
	DIO_WritePort(LCD_CTRL_PORT, RW, STD_LOW);
	delay(100);
	DIO_WritePort(LCD_CTRL_PORT, E, STD_HIGH);
	delay(100);
	DIO_Write8Bits(LCD_CTRL_PORT, command);
	delay(100);
	DIO_WritePort(LCD_CTRL_PORT, E, STD_LOW);
	delay(100);
}
void LCD_SendData (uint8 data) 
{
 LCD_CTRL_PORT = 0x01;  // setting Rs = 1 and Rw =0 
 LCD_CTRL_PORT |= 0x04; // assert enable 
 LCD_DATA_PORT = data;
 delay(100);
 LCD_CTRL_PORT = 0; 

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
