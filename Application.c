#include "Application.h"
#include "lcd.h"

uint16 counter_var = 0;

void increment (void)
{
	counter_var+=1;
	if (counter_var>999)
	{counter_var=999;}
	LCD_SendCommand(Clear_Command);
	LCD_IntegerToString(counter_var);
}
// This function is used to decrement numbers from 999 to 0 and print them to the LCD when the decrement switch is pressed
void decrement (void)
{if (counter_var==0)
     {counter_var=0;}
else{	
	counter_var-=1;
	
	LCD_SendCommand(Clear_Command);
	LCD_IntegerToString(counter_var);
		}
}
// This function is used to reset the counter to 0 and print it to the LCD screen
void reset (void)
{
	counter_var = 0;
	LCD_SendCommand(Clear_Command);
	LCD_IntegerToString(counter_var);
}
