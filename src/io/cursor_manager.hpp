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

#ifndef CURSOR_MANAGER
#define CURSOR_MANAGER

#include "io/input_manager.hpp"
#include "tools/graphic_tools.hpp"
#include "tools/geometry_tools.hpp"
#include "manager_template.hpp"

namespace AK
{

class CursorManager : public Manager<OutputManager>, public Image
{
    private:
        
        Location g_location;
        
    public:
    
// --------------------------------------------------------------------------------------
        CursorManager();
// --------------------------------------------------------------------------------------
        #define DEFAULT_CURSOR ' '
        void setCharacter(char set_character) { character = set_character; }
// --------------------------------------------------------------------------------------
        Location getClickedLocation() const { return g_location };
        bool getIfClicked() const { return InputManager::g_manager->getHitChar == '\n'; }
// --------------------------------------------------------------------------------------
        void onUpdate();
// --------------------------------------------------------------------------------------
        
};

}

#endif
