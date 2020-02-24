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

#ifndef COLOR_TOOLS
#define COLOR_TOOLS

namespace AK
{

enum class Color
{
    RED,
    YELLOW,
    GREEN,
    BLACK,
    CYAN,
    BLUE,
    MAGENTA,
    WHITE,
    DEFAULT
}; // color

// ----------------------------------------------------
#define FOREGROUND false
#define BACKGROUND true
void printColor(bool is_background, Color print_color);
// ----------------------------------------------------
void printForegroundColor(Color print_color);
void printBackgroundColor(Color print_color);
// ----------------------------------------------------
void resetColor();
// ----------------------------------------------------
Color reverseColor(Color color);
// ----------------------------------------------------

}

#endif
