/*
Here are all examples of printing texts in console with colors
*/

#include <iostream>
#include "./include/ANSIconsoleColors/ANSI_console_colors.h"


void ANSI_Examples_Demo()
{
    print("black | ", black);
    print("darkBlue | ", darkBlue);
    print("darkGreen | ", darkGreen);
    print("darkCyan | ", darkCyan);
    print("darkRed | ", darkRed);
    print("darkMagenta | ", darkMagenta);
    print("darkYellow | ", darkYellow);
    print("defaultFg | ", defaultFg);
    print("gray | ", gray);
    print("brightBlue | ", brightBlue);
    print("brightCyan | ", brightCyan);
    print("brightRed | ", brightRed);
    print("brightMagenta | ", brightMagenta);
    print("brightYellow | ", brightYellow);
    print("white | ", white);

    print("Background colors\n");

    print(" Text ", white, darkBlue);
    print(" Text ", white, darkGreen);
    print(" Text ", white, darkCyan);
    print(" Text ", white, darkRed);
    print(" Text ", white, darkMagenta);
    print(" Text ", white, darkYellow);
    print(" Text ", white, defaultFg);
    print(" Text ", white, gray);
    print(" Text ", white, brightBlue);
    print(" Text ", white, brightCyan);
    print(" Text ", white, brightRed);
    print(" Text ", white, brightMagenta);
    print(" Text \n", gray, brightYellow);
    println("______________");

    print("Print text on each line\n");

    println("black", black);
    println("darkBlue", darkBlue);
    println("darkGreen", darkGreen);
    println("darkCyan", darkCyan);
    println("darkRed", darkRed);
    println("darkMagenta", darkMagenta);
    println("darkYellow", darkYellow);
    println("defaultFg", defaultFg);
    println("gray", gray);
    println("brightBlue", brightBlue);
    println("brightCyan", brightCyan);
    println("brightRed", brightRed);
    println("brightMagenta", brightMagenta);
    println("brightYellow", brightYellow);
    println("white", white);

    println("With background colors");

    println(" Text ", white, darkBlue);
    println(" Text ", white, darkGreen);
    println(" Text ", white, darkCyan);
    println(" Text ", white, darkRed);
    println(" Text ", white, darkMagenta);
    println(" Text ", white, darkYellow);
    println(" Text ", white, defaultFg);
    println(" Text ", white, gray);
    println(" Text ", white, brightBlue);
    println(" Text ", white, brightCyan);
    println(" Text ", white, brightRed);
    println(" Text ", white, brightMagenta);
    println(" Text ", gray, brightYellow);
    println("________________");
    println("No color reset");

    printNoRst("Text", darkBlue);
    printNoRst("Text", darkBlue);

    printNoRst("Text", darkBlue, darkGreen);
    printlnNoRst("Text", darkBlue, darkGreen);

    println("______________");

    println("Print on multiple lines");

    printlnNoRst("Text", darkBlue);
    printlnNoRst("Text", darkBlue);

    printlnNoRst("Text", darkBlue, darkGreen);
    printlnNoRst("Text", darkBlue, darkGreen);
}



int main()
{
    std::cout << "Ansi code Examples\n";
    ANSI_Examples_Demo();
}