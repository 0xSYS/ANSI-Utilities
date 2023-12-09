# ANSI-Utilities
A C++ Library designed to handle ANSI escape codes easier.

The library was based on the [ANSI Escape codes tables](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797)


## Example

```c++
#include "ANSI_Utils.h"



int main()
{
    //Setting the terminal to virtual processed output (ONLY ON WINDOWS!!!)
    //SetTerminal();

    //Standard colors (Foreground, Background)
    //Dark color
    STDColorsFG(FG_Blue); //Set the foreground to blue
        printf("Blue\n"); //Display function which can be printf or cout (If used in C++ code)
    CresetAll();          //Reset all ansi escape codes

    //Bright color
    STDColorsFG(FG_Bright_Blue); //Set the text to bright blue
        printf("Bright Blue\n"); //Display function
    CresetAll();                 //Reset function

    //Both foreground and BG colors
    STDColorsFG_BG(FG_Blue, BG_Bright_Green);
        printf("Dark Blue FG + Bright Green BG\n\n");
    CresetAll();

    //Xterm colors
    XtermFG(FG, 166);
        printf("Xterm ID: 166\n");
    CresetAll();

    //Background
    XtermFG(BG, 166);
        printf("Xterm ID BG: 166\n");
    CresetAll();

    //True color
    RGB_FG(FG, 255, 80, 90);
        printf("RGB (Custom color)\n\n");
    CresetAll();

    //Background example
    RGB_FG(BG, 54, 80, 100);
        printf("RGB (Custom color)\n\n");
    CresetAll();

    //ANSI Styles

    SetStyle1(Bold);
        printf("Bold\n");
    CresetAll();

    SetStyle1(Italic);
        printf("Italic\n");
    CresetAll();

    //For more options and tests check out FullExample.c
}
```

## Windows
![bandicam 2023-12-09 21-53-52-018](https://github.com/Zidon224/ANSI-Utilities/assets/92180085/f946fc05-93da-45bc-9b6b-6975bb5862ba)


## Linux (RPi 4)
![ansiTestLinux](https://github.com/Zidon224/ANSI-Console-color-names/assets/92180085/a24167df-aea3-4a20-aae8-75c91bb6b037)


#Based on [sol-prog ansi escape codes](https://github.com/sol-prog/ansi-escape-codes-windows-posix-terminals-c-programming-examples)


