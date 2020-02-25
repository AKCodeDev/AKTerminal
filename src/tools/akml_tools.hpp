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

#ifndef AKML_TOOLS
#define AKML_TOOLS

#include "file_tools.hpp"

#include <map>
#include <string>

namespace AK
{

class AKML
{
    private:

        std::map<std::string, std::string> g_all_contents;

    public:

// --------------------------------------------
        #define CONTENT_LEFT '['
        #define CONTENT_RIGHT ']'
        #define LABEL_BEGIN 'b'
        #define LABEL_ATTRIBUTE 'a'
        #define LABEL_CONTENT 'c'
        AKML(File file);
// --------------------------------------------
        std::string get(std::string attribute);
// --------------------------------------------

};

}

#endif