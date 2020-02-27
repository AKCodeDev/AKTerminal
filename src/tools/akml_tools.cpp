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

#include "tools/akml_tools.hpp"

#include "tools/warn_tools.hpp"

#include <vector>

namespace AK
{

AKML::AKML(File file)
{
    std::string current;
    std::vector<std::string> all;
    int len;

    while(1)
    {
        current = file.getLineBetweenChar(CONTENT_LEFT, CONTENT_RIGHT);

        if(file.getLineCount() == 1)
        {
            if(all.empty())
            {
                g_version = current;
            }
            else
            {
                break;
            }
        }
        else
        {
            all.push_back(current);
        }
    }

    std::string attribute = "";
    std::string content = "";

    current = file.getLineToChar(CONTENT_LEFT);

    tryError(current[0] != LABEL_ATTRIBUTE, "No attribute before content in AKML");

    attribute = all[0];

    for(int i = 1; i < all.size(); i ++)
    {
        current = file.getLineToChar(CONTENT_LEFT);

        if(current[0] == 'a')
        {
            g_all_contents.insert(std::pair<std::string, std::string>(attribute, content));
            content = "";
            attribute = all[i];
        }
        else
        {
            content = content + '\n' + current;
        }
    }

    g_all_contents.insert(std::pair<std::string, std::string>(attribute, content));
}

}