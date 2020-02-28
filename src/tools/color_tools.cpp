/*
AKTerminal - A convinent game engine for terminal games
Copyright (C) 2019-2020 AKCodeDev

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "tools/color_tools.hpp"

#include "tools/warn_tools.hpp"

#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#elif __unix__
    #include <unistd.h>
#endif

namespace AK
{

#ifdef _WIN32
int g_saved_foreground;
int g_saved_background;

void setSaved(bool is_background, int value)
{
    if(is_background)
        g_saved_background = value;
    else
        g_saved_foreground = value;
}
#endif

void printColor(bool is_background, Color print_color)
{
    switch(print_color)
    {
        case Color::RED:
            // Print red
#ifdef _WIN32
            setSaved(is_background, 0xc);
#elif __unix__
            std::cout << (is_background ? "\033[41m" : "\033[31m");
#endif
            break;

        case Color::YELLOW:
            // Print yellow
#ifdef _WIN32
            setSaved(is_background, 0xe);
#elif __unix__
            std::cout << (is_background ? "\033[42m" : "\033[32m");
#endif
            break;

        case Color::GREEN:
            // Print green
#ifdef _WIN32
            setSaved(is_background, 0xa);
#elif __unix__
            std::cout << (is_background ? "\033[43m" : "\033[33m");
#endif
            break;
            
        case Color::BLACK:
            // Print black
#ifdef _WIN32
            setSaved(is_background, 0);
#elif __unix__
            std::cout << (is_background ? "\033[40m" : "\033[30m");
#endif
            break;

        case Color::CYAN:
            // Print cyan
#ifdef _WIN32
            setSaved(is_background, 0xb);
#elif __unix__
            std::cout << (is_background ? "\033[46m" : "\033[36m");
#endif
            break;

        case Color::BLUE:
            // Print blue
#ifdef _WIN32
            setSaved(is_background, 0x9);
#elif __unix__
            std::cout << (is_background ? "\033[44m" : "\033[34m");
#endif
            break;

        case Color::MAGENTA:
            // Print magenta
#ifdef _WIN32
            setSaved(is_background, 0xd);
#elif __unix__
            std::cout << (is_background ? "\033[45m" : "\033[35m");
#endif
            break;

        case Color::WHITE:
            // Print white
#ifdef _WIN32
            setSaved(is_background, 0xf);
#elif __unix__
            std::cout << (is_background ? "\033[47m" : "\033[37m");
#endif
            break;

        case Color::DEFAULT:
            // Print default
            std::cout << (is_background ? "\033[40m" : "\033[37m");
            return;
    }
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g_saved_background * 0x10 + g_saved_foreground);
#endif
} // printColor

void printForegroundColor(Color print_color)
{
    printColor(FOREGROUND, print_color);
} // printForegroundColor

void printBackgroundColor(Color print_color)
{
    printColor(BACKGROUND, print_color);
} // printBackgroundColor

void resetColor()
{
#ifdef _WIN32
    g_saved_foreground = 0xf;
    g_saved_background = 0;
    SetConsoleTextAttribute(handle, 0xf);
#elif __unix__
    std::cout << "\033[0m";
#endif
} // resetColor

Color charToColor(char character)
{
    switch(character)
    {
        case 'r':
        case 'R':
            return Color::RED;
        case 'g':
        case 'G':
            return Color::GREEN;
        case 'b':
        case 'B':
            return Color::BLUE;
        case 'k':
        case 'K':
            return Color::BLACK;
        case 'y':
        case 'Y':
            return Color::YELLOW;
        case 'c':
        case 'C':
            return Color::CYAN;
        case 'm':
        case 'M':
            return Color::MAGENTA;
        case 'w':
        case 'W':
            return Color::WHITE;
        case 'd':
        case 'D':
            return Color::DEFAULT;
        default:
            throwError("Invalid color char");
    }
}

Color reverseColor(Color color)
{
	if(color == Color::DEFAULT)
	{
		return Color::DEFAULT;
	}
    return (Color)(((int)color + (int)Color::DEFAULT / 2) % (int)Color::DEFAULT);
} // reverseColor

}
