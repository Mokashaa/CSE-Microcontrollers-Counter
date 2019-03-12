#include "lcd.h"

void delay (uint32_t x)
{
	while(x != 0)
		x--;
}

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

}
