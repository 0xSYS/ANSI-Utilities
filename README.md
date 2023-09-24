# ANSI-Console-color-names
A C++ Library designed to handle ANSI escape codes easier.

This is a re-write of the basic example found [here](https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c)

The library was based on the [ANSI Escape codes tables](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797)

This is a wip project, it may have bugs and it wasn't acurately tested.

# Important note!!! This library uses c++ 17

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

   //Print text with colors (order foreground - background)
   print("This text is blue", darkBlue);

   //Set the text color and bacground colors
   print("Blue text with green bacground color", darkBlue, darkGreen);

   //Print text with the same color (No color reset)
   printNoRst("The text on the rest of the lines is the same", darkRed);

   //Print without reseting the text color but on different line
   printlnNoRst("The text on the rest of the lines is the same but not on the same line", darkRed);

   //Overload the print functions with undefined numbers and types of parameters
   std::string str = "This string comes from the str variable";
   print("Standard Text", darkBlue, " New text", str);
   //And the same things can be done for all print type functions


   //color names:
   //For Both foreground and background
   //black
   //darkBlue
   //darkGreen
   //darkCyan
   //darkRed
   //darkMagenta
   //darkYellow
   //defaultFg
   //gray
   //brightBlue
   //brightGreen
   //brightCyan
   //brightRed
   //brightMagenta
   //brightYellow
   //white
}
```

preview (Example from basic.cpp):
![Screenshot 2023-09-23 214753](https://github.com/PianoArts2007/ANSI-Console-color-names/assets/92180085/b300e600-dcf5-43cc-a2e2-aa5fa99ae6e8)

### Check out examples/basic.cpp for all available colors and combinations
