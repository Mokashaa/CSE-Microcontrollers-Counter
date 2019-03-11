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
{uint8 temp;
	temp=(i/100)+48;// convert first digit to ascii
	char x;
	x=temp;
	LCD_COMMAND(0x80);//first digit 
	LCD_DATA(x);
	temp=(temp/10)+48;// convert second digit to ascii
	x=temp;
	LCD_COMMAND(0x81);
	LCD_DATA(x);
	temp=(i%10)+48;	// convert third digit to ascii
	x=temp;
	LCD_COMMAND(0x82);
	LCD_DATA(x);
}

void LCD_IntegerToString (uint16 data)
{

}
void LCD_Init (void)
{

}
