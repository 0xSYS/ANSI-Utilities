#pragma once


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #define VC_EXTRALEAN
    #include <Windows.h>
#endif


//All of this shit is for windows's stupid API
#ifdef _WIN32
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
        #define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
    #endif

    static HANDLE stdoutHandle, stdinHandle;
    static DWORD outModeInit, inModeInit;

    static inline void SetTerminal()
    {
        DWORD outMode = 0, inMode = 0;
        stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        stdinHandle = GetStdHandle(STD_INPUT_HANDLE);

        if(stdoutHandle == INVALID_HANDLE_VALUE || stdinHandle == INVALID_HANDLE_VALUE) 
        {
            exit(GetLastError());
        }
    
        if(!GetConsoleMode(stdoutHandle, &outMode) || !GetConsoleMode(stdinHandle, &inMode)) 
        {
            exit(GetLastError());
        }

        outModeInit = outMode;
        inModeInit = inMode;
    
        // Enable ANSI escape codes
        outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

        // Set stdin as no echo and unbuffered
        inMode &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);

        if(!SetConsoleMode(stdoutHandle, outMode) || !SetConsoleMode(stdinHandle, inMode)) 
        {
            exit(GetLastError());
        }    
    }
#endif

//Standard ansi colors
enum StandardColors
{
    Reset,
    FG_Black = 30,
    FG_Red,
    FG_Green,
    FG_Yellow,
    FG_Blue,
    FG_Magenta,
    FG_Cyan,
    FG_White,
    FG_Default = 39,
    BG_Black = 40,
    BG_Red,
    BG_Green,
    BG_Yellow,
    BG_Blue,
    BG_Magenta,
    BG_Cyan,
    BG_White,
    BG_Default = 49,
    FG_Bright_Black = 90,
    FG_Bright_Red,
    FG_Bright_Green,
    FG_Bright_Yellow,
    FG_Bright_Blue,
    FG_Bright_Magenta,
    FG_Bright_Cyan,
    FG_Bright_White,
    BG_Bright_Black = 100,
    BG_Bright_Red,
    BG_Bright_Green,
    BG_Bright_Yellow,
    BG_Bright_Blue,
    BG_Bright_Magenta,
    BG_Bright_Cyan,
    BG_Bright_White,
};

//Text styles
enum TextStyles
{
    Bold = 1,
    Dimm,
    Italic,
    Underline,
    Blink,
    Reverse = 7,
    Hidden,
    Striketrough
};

//Reset text styles
enum RstTextStyles
{
    RstBoldAndDimm = 22,
    RstItalic,
    RstUnderline,
    RstBlinkMode,
    RstReverse = 27,
    RstHidden,
    RstStrikeTrough
};

//Aditional flags for Xterm and true color RGB
enum Xterm_RGB
{
    FG = 38,
    BG = 48
};


//plain functions

static inline void STDColorsFG(int codeNumFG)
{
    printf("\033[%dm", codeNumFG);
}

static inline void STDColorsFG_BG(int codeNumFG, int codeNumBG)
{
    printf("\033[%d;%dm", codeNumFG, codeNumBG);
}

static inline void XtermFG(int getFG1, int XtermID)
{
    printf("\033[%d;5;%dm", getFG1, XtermID);
}

static inline void XtermFG_BG(int getFG2, int XtermFGID, int getBG1, int XtermBGID)
{
    printf("\033[%d;5;%d;%d;5;%dm", getFG2, XtermFGID, getBG1, XtermBGID);
}

static inline void RGB_FG(int getFG3, int R, int G, int B)
{
    printf("\033[%d;2;%d;%d;%dm", getFG3, R, G, B);
}

static inline void RGB_FG_BG(int getFG4, int R, int G, int B, int getBG2, int bR, int bG, int bB)
{
    printf("\033[%d;2;%d;%d;%d;%d;2;%d;%d;%dm", getFG4, R, G, B, getBG2, bR, bG, bB);
}

static inline void CresetAll()
{
    //std::cout << "\033[0m";
    printf("\033[0m");
}

//Function overloading

#define COUNT_PARMS2(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _, ...) _
#define COUNT_PARMS(...)COUNT_PARMS2(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)


static inline void count_overload_aux(int count, ...)
{
    va_list v;
    va_start(v, count);

    switch(count)
    {
        case 1:
        {
            int codeNumFG = va_arg(v, int);
            STDColorsFG(codeNumFG);
            break;
        }

        case 2:
        {
            int codeNumFG = va_arg(v, int);
            int codeNumBG = va_arg(v, int);
            STDColorsFG_BG(codeNumFG, codeNumBG);
            break;
        }

        case 3:
        {
            int getFG1 = va_arg(v, int);
            int XtermID = va_arg(v, int);
            XtermFG(getFG1, XtermID);
            break;
        }

        case 4:
        {
            int getFG2 = va_arg(v, int);
            int XtermFGID = va_arg(v, int);
            int getBG1 = va_arg(v, int);
            int XtermBGID = va_arg(v, int);
            XtermFG_BG(getFG2, XtermFGID, getBG1, XtermBGID);
            break;
        }

        default:
        {
            va_end(v);

            printf("Invalid arguments to function 'Ctext()'");
            exit(1);
        }
    }

    va_end(v);
}

#define Ctext(...)count_overload_aux(COUNT_PARMS(__VA_ARGS__), __VA_ARGS__)
