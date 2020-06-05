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
#include "base/geometry.hpp"
#include "base/graphic.hpp"
#include "base/manager.hpp"

namespace AK
{

class CursorManager : public Manager<CursorManager>
{
    private:
        
        Location g_location;
        Pixel g_pixel = (Color::ALPHA, Color::REVERSE);
        
    public:
    
// ------------------------------------------------------------------------------------
        CursorManager();
// ------------------------------------------------------------------------------------
        void setCharacter(char set_character) { g_pixel.character = set_character; }
// ------------------------------------------------------------------------------------
        Location getClickedLocation() const { return g_location; };
        bool getIfClicked() const { return InputManager::get() -> getHitChar == '\n'; }
// ------------------------------------------------------------------------------------
        void onUpdate();
// ------------------------------------------------------------------------------------
        
};

}

#endif
