/*
MIT License

Copyright (c) 2023 PianoArts2007

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/



#pragma once



#include <iostream>
#include <string>

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #define VC_EXTRALEAN
    #include <Windows.h>
#endif




//DO NOT CHANGE ANYTHING HERE!!!
const int black         = 0;
const int darkBlue      = 1;
const int darkGreen     = 2;
const int darkCyan      = 3;
const int darkRed       = 4;
const int darkMagenta   = 5;
const int darkYellow    = 6;
const int defaultFg     = 7;
const int gray          = 8;
const int brightBlue    = 9;
const int brightGreen   = 10;
const int brightCyan    = 11;
const int brightRed     = 12;
const int brightMagenta = 13;
const int brightYellow  = 14;
const int white         = 15;



std::string getTextColorCode(const int fgColor)
{
    switch (fgColor)
    {
        //DO NOT CHANGE ANYTHING HERE!!!
        case  0: return "30";
        case  1: return "31";
        case  2: return "32";
        case  3: return "33";
        case  4: return "34";
        case  5: return "35";
        case  6: return "36";
        case  7: return "37";
        case  8: return "39";
        case  9: return "0";
        case 10: return "90";
        case 11: return "91";
        case 12: return "92";
        case 13: return "93";
        case 14: return "94";
        case 15: return "95";
    }
}

std::string getBgColorCode(const int bgColor)
{
    switch (bgColor)
    {
        //DO NOT CHANGE ANYTHING HERE!!!
        case  0: return "40";
        case  1: return "41";
        case  2: return "42";
        case  3: return "43";
        case  4: return "44";
        case  5: return "45";
        case  6: return "46";
        case  7: return "47";
        case  8: return "49";
        case  9: return "0";
        case 10: return "100";
        case 11: return "101";
        case 12: return "102";
        case 13: return "103";
        case 14: return "104";
        case 15: return "105";
    }
}

std::string getPrintColor(const int fgColor)
{
    return "\x1b[" + getTextColorCode(fgColor) + "m";
}

std::string getPrintColor(const int fgColor, const int bgColor)
{
    return "\x1b[" + getTextColorCode(fgColor) + ";" + getBgColorCode(bgColor) + "m";
}

void printColor(const int fgColor)
{
    #if defined(_WIN32)
        static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, fgColor);
    #elif defined(__linux__)
        std::cout << getPrintColor(fgColor);
    #endif
}

void printColor(const int fgColor, const int bgColor)
{
    #if defined(_WIN32)
        static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, bgColor << 4 | fgColor);
    #elif defined(__linux__)
        std::cout << getPrintColor(fgColor, bgColor);
    #endif
}

void printColorRst()
{
    #if defined(_WIN32)
        static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, 7);
    #elif defined(__linux__)
        std::cout << "\x1b[0m";
    #endif
}

void println(const std::string& s = "")
{
    std::cout << s << std::endl;
}

void println(const std::string& s, const int fgColor)
{
    printColor(fgColor);
    std::cout << s << std::endl;
    printColorRst();
}

void println(const std::string& s, const int fgColor, const int bgColor)
{
    printColor(fgColor, bgColor);
    std::cout << s << std::endl;
    printColorRst();
}

void print(const std::string& s = "")
{
    std::cout << s;
}

void print(const std::string& s, const int fgColor)
{
    printColor(fgColor);
    std::cout << s;
    printColorRst();
}

void print(const std::string& s, const int fgColor, const int bgColor)
{
    printColor(fgColor, bgColor);
    std::cout << s;
    printColorRst();
}

void printNoRst(const std::string& s, const int fgColor)
{
    printColor(fgColor);
    std::cout << s;
}

void printNoRst(const std::string& s, const int fgColor, const int bgColor)
{
    printColor(fgColor, bgColor);
    std::cout << s;
}

void printlnNoRst(const std::string& s, const int fgColor)
{
    printColor(fgColor);
    std::cout << s << std::endl;
}

void printlnNoRst(const std::string& s, const int fgColor, const int bgColor)
{
    printColor(fgColor, bgColor);
    std::cout << s << std::endl;
}