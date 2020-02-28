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

#ifndef WARN_TOOLS
#define WARN_TOOLS

#include <string>

namespace AK
{

// --------------------------------------------------------------------
void tryError(bool condition, std::string message, int return_val = 1);
// --------------------------------------------------------------------
void throwError [[noreturn]] (std::string message, int return_val = 1);
// --------------------------------------------------------------------
void tryWarn(bool condition, std::string message);
// --------------------------------------------------------------------
void throwWarn(std::string message);
// --------------------------------------------------------------------

}

#endif 
