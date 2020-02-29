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

#include "file/file.hpp"

#include "tools/warn_tools.hpp"

#include <iostream>

File::File(std::string filename, std::string file_namespace = "")
{
    g_stream.open(file_namespace + filename);
    g_line_count = 0;
}

File::~File()
{
    g_stream.close();
}

void File::reset()
{
    g_stream.clear();
    g_line_count = 0;
}

std::string File::getLine()
{
    std::string ret;
    if(!getline(g_stream, ret))
    {
        reset();
        return getLine();
    }
    g_line_count ++;
    return ret;
}

std::string File::getLineToChar(char to_char)
{
    std::string str = getLine();
    std::string::size_type position = str.find(to_char);

    tryError(position == std::string::npos, ("Didn't find char %c in class \"File\"", to_char));

    return str.substr(0, position);
}

std::string File::getLineFromChar(char from_char)
{
    std::string str = getLine();
    std::string::size_type position = str.find(from_char);

    tryError(position == std::string::npos, ("Didn't find char %c in class \"File\""));

    return str.substr(position + 1);
}

std::string File::getLineBetweenChar(char from_char, char to_char)
{
    std::string str = getLine();
    std::string::size_type from_position = str.find_first_of(from_char);
    std::string::size_type to_position = str.find_last_of(to_char);

    tryError(from_position == std::string::npos, ("Didn't find char %c in class \"File\"", from_char));
    tryError(to_position == std::string::npos, ("Didn't find char %c in class \"File\"", to_char));

    return str.substr(from_position + 1, to_position - from_position);
}

void File::goToLastLine()
{
    g_stream.seekg(-1, std::ios::cur);
}