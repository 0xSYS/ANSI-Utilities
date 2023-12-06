#include "AnsiCodes/re-write6.h"


int main()
{
    SetTerminal(); //Only for windows



    printf("Unicode Test: ██████████████████░░░░░░░░░░░░░░░░░\n");

   

    STDColorsFG(FG_Cyan);
        printf("Thing\n");
    CresetAll();

    STDColorsFG_BG(FG_Red, BG_Bright_Yellow);
        printf("Thing\n");
    CresetAll();

    XtermFG(FG, 48);
        printf("Xterm Thing\n");
    CresetAll();

    XtermFG_BG(FG, 48, BG, 128);
        printf("Thing\n");
    CresetAll();

    RGB_FG(FG, 255, 100, 20);
        printf("Thing\n");
    CresetAll();

    RGB_FG_BG(FG, 255, 100, 20, BG, 20, 100, 255);
        printf("Thing\n");
    CresetAll();

    SetStyle1(Striketrough);
        printf("Bold\n");
    CresetAll();

    SetStyle2(Blink, Reverse);
        printf("Bold + Underline\n");
    CresetAll();

    SetStyle3(Blink, Italic, Underline);
        printf("Blink + Italic + Underline\n");
    CresetAll();
}
