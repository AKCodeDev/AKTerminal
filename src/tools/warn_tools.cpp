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

#include "tools/warn_tools.hpp"

#include "tools/color_tools.hpp"
#include "tools/system_tools.hpp"

#include <cstdlib>
#include <iostream>

namespace AK
{

void tryError(bool condition, std::string message, int return_val = 1)
{
    if(return_val == 0)
        throwError("Invalid return value in tryError()");

    if(condition)
        throwError(message, return_val);
}

void throwError(std::string message, int return_val = 1)[[noreturn]]
{
    if(return_val == 0)
        throwError("Invalid return value in throwError()");
    
    printBackgroundColor(Color::RED);
    cout << message << endl;
    resetColor();
    cout << "Press \"Enter\" to quit" << endl;
    
    while(1)
    {
        if(getch == "\n")
            exit(return_val);
    }
}

void tryWarn(bool condition, std::string message)
{
    if(return_val == 0)
        throwError("Invalid return value in tryWarn()");

    if(condition)
        throwWarn(message, return_val);
}

void throwWarn(std::string message)
{
    if(return_val == 0)
        throwError("Invalid return value in throwWarn()");
    
    printBackgroundColor(Color::YELLOW);
    cout << message << endl;
    resetColor();
    cout << "Press \"Enter\" to continue" << endl;
    
    while(1)
    {
        if(getch == "\n")
            break;
    }
}

}
