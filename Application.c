#include "Application.h"

void increment (void)
{
	i=i+1;
	if (i>999)
	{i=999;}
	LCD_IntegerToString(i);
}
// This function is used to decrement numbers from 999 to 0 and print them to the LCD when the decrement switch is pressed
void decrement (void)
{
	
}
// This function is used to reset the counter to 0 and print it to the LCD screen
void reset (void)
{
	
}
