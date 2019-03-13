#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "port.h"
#include "DIO.h"

// This function is used to increment numbers from 0 to 999 and print them to the LCD when the increment switch is pressed
void increment (void);
// This function is used to decrement numbers from 999 to 0 and print them to the LCD when the decrement switch is pressed
void decrement (void);
// This function is used to reset the counter to 0 and print it to the LCD screen
void reset (void);

#endif
