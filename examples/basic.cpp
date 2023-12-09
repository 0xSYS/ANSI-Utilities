#include "include/ANSIconsoleColors/ANSI_console_colors.h"



int main()
{
    SetTerminal(); //Disable this function if you use Linux
    
    printf("#### Standard colors ####\n\n");

    printf("- Dark colors foreground \n");

    STDColorsFG(FG_Red);
        printf("Red\n");
    CresetAll();

    STDColorsFG(FG_Green);
        printf("Green\n");
    CresetAll();

    STDColorsFG(FG_Yellow);
        printf("Yellow\n");
    CresetAll();

    STDColorsFG(FG_Blue);
        printf("Blue\n");
    CresetAll();

    STDColorsFG(FG_Magenta);
        printf("Magenta\n");
    CresetAll();

    STDColorsFG(FG_Cyan);
        printf("Cyan\n");
    CresetAll();

    STDColorsFG(FG_White);
        printf("White\n");
    CresetAll();

    STDColorsFG(FG_Default);
        printf("Default\n\n");
    CresetAll();

    printf("- Dark colors Background\n");

    STDColorsFG(BG_Red);
        printf("Red\n");
    CresetAll();

    STDColorsFG(BG_Green);
        printf("Green\n");
    CresetAll();

    STDColorsFG(BG_Yellow);
        printf("Yellow\n");
    CresetAll();

    STDColorsFG(BG_Blue);
        printf("Blue\n");
    CresetAll();

    STDColorsFG(BG_Magenta);
        printf("Magenta\n");
    CresetAll();

    STDColorsFG(BG_Cyan);
        printf("Cyan\n");
    CresetAll();

    STDColorsFG(BG_White);
        printf("White\n");
    CresetAll();

    STDColorsFG(BG_Default);
        printf("Default\n\n");
    CresetAll();

    printf("#### Bright Colors foreground\n");

    STDColorsFG(FG_Bright_Red);
        printf("Bright Red\n");
    CresetAll();

    STDColorsFG(FG_Bright_Green);
        printf("Bright Green\n");
    CresetAll();

    STDColorsFG(FG_Bright_Yellow);
        printf("Bright Yellow\n");
    CresetAll();

    STDColorsFG(FG_Bright_Blue);
        printf("Bright Blue\n");
    CresetAll();

    STDColorsFG(FG_Bright_Magenta);
        printf("Bright Magenta\n");
    CresetAll();

    STDColorsFG(FG_Bright_Cyan);
        printf("Bright Cyan\n");
    CresetAll();

    STDColorsFG(FG_Bright_White);
        printf("Bright White\n");
    CresetAll();

    STDColorsFG(FG_Bright_Black);
        printf("Bright Black\n\n");
    CresetAll();

    printf("- Bright Colors background\n");

    STDColorsFG(BG_Bright_Red);
        printf("Bright Red\n");
    CresetAll();

    STDColorsFG(BG_Bright_Green);
        printf("Bright Green\n");
    CresetAll();

    STDColorsFG(BG_Bright_Yellow);
        printf("Bright Yellow\n");
    CresetAll();

    STDColorsFG(BG_Bright_Blue);
        printf("Bright Blue\n");
    CresetAll();

    STDColorsFG(BG_Bright_Magenta);
        printf("Bright Magenta\n");
    CresetAll();

    STDColorsFG(BG_Bright_Cyan);
        printf("Bright Cyan\n");
    CresetAll();

    STDColorsFG(BG_Bright_White);
        printf("Bright White\n");
    CresetAll();

    STDColorsFG(BG_Bright_Black);
        printf("Bright Black\n\n");
    CresetAll();

    printf("#### Standard color combinations ####\n\n");

    printf("- Dark colors + Bright Colors\n");

    STDColorsFG_BG(FG_Blue, BG_Bright_Green);
        printf("Dark Blue FG + Bright Green BG\n\n");
    CresetAll();

    printf("#### 256 Colors ####\n");

    printf("- Foreground \n");

    for(int i = 0; i < 256; i++)
    {
        XtermFG(FG, i);
            printf("Xterm ID: %d\n", i);
        CresetAll();
    }

    printf("\n\n");

    printf("- Background\n");

    for(int i = 0; i < 256; i++)
    {
        XtermFG(BG, i);
            printf("Xterm background ID: %d\n", i);
        CresetAll();
    }

    printf("\n\n");

    printf("#### True color RGB ####\n\n");

    printf("- Foreground\n");

    RGB_FG(FG, 255, 80, 90);
        printf("RGB (Custom color)\n\n");
    CresetAll();

    printf("- Background\n");

    RGB_FG(BG, 54, 80, 100);
        printf("RGB (Custom color)\n\n");
    CresetAll();

    printf("#### Text Styles\n");

    SetStyle1(Bold);
        printf("Bold\n");
    CresetAll();

    SetStyle1(Italic);
        printf("Italic\n");
    CresetAll();

    SetStyle1(Underline);
        printf("Underline\n");
    CresetAll();

    SetStyle1(Striketrough);
        printf("Striketrough\n");
    CresetAll();

    SetStyle1(Dimm);
        printf("Dimm\n");
    CresetAll();

    SetStyle1(Blink);
        printf("Blink\n");
    CresetAll();

    SetStyle1(Reverse);
        printf("Reverse\n\n");
    CresetAll();

    printf("- 2 Styles combinations\n");

    SetStyle2(Italic, Underline);
        printf("Italic + Underline\n\n");
    CresetAll();

    printf("- 3 Styles combination\n");

    SetStyle3(Dimm, Italic, Striketrough);
        printf("Dimm + Italic + Striketrough\n\n");
    CresetAll();

    printf("- Styles and standard colors\n");

    Style1FGColor(Italic, FG_Cyan);
        printf("Italic + Cyan\n");
    CresetAll();

    Style1FGColor(Underline, FG_Magenta);
        printf("Underline + Magenta\n");
    CresetAll();

    Style1FGColor(Dimm, FG_Bright_Yellow);
        printf("Dimm + Bright Yellow\n");
    CresetAll();

    Style2FGColor(Underline, FG_Blue, BG_Green);
        printf("Underline + Blue FG + Green BG\n");
    CresetAll();

    Style2FGColor(Dimm, Italic, FG_Red);
        printf("Dimm + Italic + Red FG\n");
    CresetAll();

    Style2FG_BGColor(Dimm, Italic, FG_Green, BG_Bright_Blue);
        printf("Dimm + Italic + FG Green + BG Bright Blue\n");
    CresetAll();

    Style3FGColor(Dimm, Italic, Reverse, FG_Bright_Red);
        printf("Dimm + Italic + Reverse + Bright red\n");
    CresetAll();

    Style3FGColor(Underline, Striketrough, Blink, FG_Cyan);
        printf("Underline + Striketrough + Blink + Cyan FG\n");
    CresetAll();

    Style3FG_BGColor(Dimm, Underline, Italic, FG_Blue, BG_Bright_Cyan);
        printf("Dimm + Underline + Italic + FG Blue + BG Bright Cyan\n");
    CresetAll();

    Style1Xterm(Underline, FG, 48);
        printf("Underline + Xterm ID: 48\n");
    CresetAll();

    Style2Xterm(Underline, Italic, FG, 128);
        printf("Underline + Italic + Xterm ID: 128\n");
    CresetAll();

    Style3Xterm(Underline, Blink, Italic, FG, 166);
        printf("Underline + Blink, Italic + Xterm ID: 166\n");
    CresetAll();

    Style1XtermFG_BG(Italic, FG, 34, BG, 166);
        printf("Italic + Xterm FG ID: 34 + Xterm BG ID: 166\n\n");
    CresetAll();
    printf("#### Unicode support (UTF 8) ####\n");

    printf("50% ██████████████░░░░░░░░░\n");

}
