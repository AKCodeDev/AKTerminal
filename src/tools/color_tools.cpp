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

#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#elif __unix__
    #include <unistd.h>
#endif

namespace AK
{

void printColor(bool is_background, Color print_color)
{
#ifdef _WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    int intensity = is_background ? BACKGROUND_INTENSITY : FOREGROUND_INTENSITY;
    int red = is_background ? BACKGROUND_RED : FOREGROUND_RED;
    int green = is_background ? BACKGROUND_GREEN : FOREGROUND_GREEN;
    int blue = is_background ? BACKGROUND_BLUE : FOREGROUND_BLUE;
#endif

    switch(print_color)
    {
        case Color::BLACK:
            // Print black
#ifdef _WIN32
            SetConsoleTextAttribute(handle, intensity);
#elif __unix__
            std::cout << (is_background ? "\033[40m" : "\033[30m");
#endif
            break;

        case Color::RED:
            // Print red
#ifdef _WIN32
            SetConsoleTextAttribute(handle, intensity | red);
#elif __unix__
            std::cout << (is_background ? "\033[41m" : "\033[31m");
#endif
            break;

        case Color::YELLOW:
            // Print yellow
#ifdef _WIN32
            SetConsoleTextAttribute(handle, intensity | red | green);
#elif __unix__
            std::cout << (is_background ? "\033[42m" : "\033[32m");
#endif
            break;

        case Color::GREEN:
            // Print green
#ifdef _WIN32
            SetConsoleTextAttribute(handle, intensity | green);
#elif __unix__
            std::cout << (is_background ? "\033[43m" : "\033[33m");
#endif
            break;

        case Color::CYAN:
            // Print cyan
#ifdef _WIN32
            SetConsoleTextAttribute(handle, intensity | green | blue);
#elif __unix__
            std::cout << (is_background ? "\033[46m" : "\033[36m");
#endif
            break;

        case Color::BLUE:
            // Print blue
#ifdef _WIN32
            SetConsoleTextAttribute(handle, intensity | blue);
#elif __unix__
            std::cout << (is_background ? "\033[44m" : "\033[34m");
#endif
            break;

        case Color::MAGENTA:
            // Print magenta
#ifdef _WIN32
            SetConsoleTextAttribute(handle, intensity | red | blue);
#elif __unix__
            std::cout << (is_background ? "\033[45m" : "\033[35m");
#endif
            break;

        case Color::WHITE:
            // Print white
#ifdef _WIN32
            SetConsoleTextAttribute(handle, intensity | red | green | blue);
#elif __unix__
            std::cout << (is_background ? "\033[47m" : "\033[37m");
#endif
            break;

        case Color::DEFAULT:
            // Print default
            resetColor();
            break;
    }
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
    SetConsoleTextAttribute(handle, intensity);
#elif __unix__
    std::cout << "\033[0m";
#endif
} // resetColor

}
