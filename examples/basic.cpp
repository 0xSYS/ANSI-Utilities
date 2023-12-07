#include "include/ANSIconsoleColors/ANSI_console_colors.h"



int main()
{
    //Basic colors (These colors are supported by any terminal)

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

}
