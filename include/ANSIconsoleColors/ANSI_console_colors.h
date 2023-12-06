#pragma once



#include <stdio.h>
#include <stdint.h> //For muchless memory usage
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
        SetConsoleOutputCP(CP_UTF8); //Enabling unicode charset on windows console
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



//Ansi Settings functions

static inline void STDColorsFG(uint8_t codeNumFG)
{
    printf("\033[%dm", codeNumFG); 
}

static inline void STDColorsFG_BG(uint8_t codeNumFG, uint8_t codeNumBG)
{
    printf("\033[%d;%dm", codeNumFG, codeNumBG);
}

static inline void XtermFG(uint8_t getFG1, uint8_t XtermID)
{
    printf("\033[%d;5;%dm", getFG1, XtermID);
}

static inline void XtermFG_BG(uint8_t getFG2, uint8_t XtermFGID, uint8_t getBG1, uint8_t XtermBGID)
{
    printf("\033[%d;5;%d;%d;5;%dm", getFG2, XtermFGID, getBG1, XtermBGID); 
}

static inline void RGB_FG(uint8_t getFG3, uint8_t R, uint8_t G, uint8_t B)
{
    printf("\033[%d;2;%d;%d;%dm", getFG3, R, G, B);
}

static inline void RGB_FG_BG(uint8_t getFG4, uint8_t R, uint8_t G, uint8_t B, uint8_t getBG2, uint8_t bR, uint8_t bG, uint8_t bB)
{
    printf("\033[%d;2;%d;%d;%d;%d;2;%d;%d;%dm", getFG4, R, G, B, getBG2, bR, bG, bB);
}

static inline void SetStyle1(uint8_t style)
{
    printf("\033[%dm", style);
}

static inline void SetStyle2(uint8_t style1, uint8_t style2)
{
    printf("\033[%d;%dm", style1, style2);
}

static inline void SetStyle3(uint8_t style1, uint8_t style2, uint8_t style3)
{
    printf("\033[%d;%d;%dm", style1, style2, style3);
}

static inline void CresetAll()
{
    printf("\033[0m");
}
