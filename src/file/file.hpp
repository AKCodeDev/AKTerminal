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

#ifndef FILE_TOOLS
#define FILE_TOOLS

#include <fstream>
#include <string>

class File
{
    private:

        std::ifstream g_stream;

        int g_line_count;

    public:

// ------------------------------------------------------------------
        File(std::string filename, std::string file_namespace);
        ~File();
// ------------------------------------------------------------------
        void reset();
// ------------------------------------------------------------------
        std::string getLine();
        std::string getLineToChar(char to_char);
        std::string getLineFromChar(char from_char);
        std::string getLineBetweenChar(char from_char, char to_char);    
// ------------------------------------------------------------------
        void goToLastLine();
// ------------------------------------------------------------------
        int getLineCount() const { return g_line_count; }
// ------------------------------------------------------------------

};

#endif