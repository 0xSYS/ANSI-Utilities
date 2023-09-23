# ANSI-Console-color-names
A C++ Library designed to handle ANSI escape codes easier.

This is a re-write of the basic example found [here](https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c)

The library was based on the [ANSI Escape codes tables](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797)

This is a wip project, it may have bugs and it wasn't acurately tested.

## Example

```c++
#include "ANSI_console_colors.h"

int main()
{
   //Unstyled text
   print("Standard text");

   //print text to a new line
   println("This text goes to a new line");

   //Or use "\n" to do the same thing using print function
   print("This text goes to a new line\n");

   //Print text with colors
   print("This text is blue", darkBlue);

   //Set the text color and bacground colors
   print("Blue text with green bacground color", darkBlue, darkGreen);

   //Print text with the same color (No color reset)
   printNoRst("The text on the rest of the lines is the same", darkRed);

   //Print without reseting the text color but on different line
   printlnNoRst("The text on the rest of the lines is the same but not on the same line", darkRed);
}
```
### Check out examples/basic.cpp for all available colors and combinations
