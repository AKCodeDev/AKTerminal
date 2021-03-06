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

#include "io/cursor_manager.hpp"

#include "io/output_manager.hpp"
#include "tools/color_tools.hpp"

#include <algorithm>

namespace AK
{


void CursorManager::onUpdate()
{
    if(!g_enable)
    {
        return;
    }

    if(InputManager::get()->getHitChar() == LEFT_ARROW)
    {
        g_location.x = std::max(g_location.x - 1, 0);
    }
    else if(InputManager::get()->getHitChar() == UP_ARROW)
    {
        g_location.y = std::max(g_location.y - 1, 0);
    }
    else if(InputManager::get()->getHitChar() == RIGHT_ARROW)
    {
        g_location.x = std::max(g_location.x + 1, 0);
    }
    else if(InputManager::get()->getHitChar() == DOWN_ARROW)
    {
        g_location.y = std::max(g_location.y + 1, 0);
    }
    
    OutputManager::get()->setPixel(g_pixel, g_location);
}

}
