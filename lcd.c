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

}
void LCD_DisplayString (uint16 i)
{ 
	uint8 temp;
	char x;
	temp=(i/100)+48;// convert first digit to ascii
	x=temp;
	LCD_SendCommand(0x80);//first digit 
	LCD_SendData(x);
	temp=(temp/10)+48;// convert second digit to ascii
	x=temp;
	LCD_SendCommand(0x81);
	LCD_SendData(x);
	temp=(i%10)+48;	// convert third digit to ascii
	x=temp;
	LCD_SendData(0x82);
	LCD_SendData(x);
}

void LCD_IntegerToString (uint16 data)
{

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
