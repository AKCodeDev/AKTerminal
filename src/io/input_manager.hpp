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

#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "manager_template.hpp"

namespace AK
{

class InputManager : public Manager<InputManager>
{
    private:
        
        char g_hit_char = EOF;
        bool g_if_start_press = false;
        bool g_if_end_press = false;
        
    public:
    
// ---------------------------------------------------------------------------------
        #define LEFT_ARROW 75
        #define UP_ARROW 72
        #define RIGHT_ARROW 77
        #define DOWN_ARROW 80
        char getHitChar() const { return g_hit_char; }
        char getStartHitChar() const { return g_if_start_press ? g_hit_char : EOF; }
        char getEndHitChar() const { return g_if_end_press ? g_hit_char : EOF; }
// ---------------------------------------------------------------------------------
        void onUpdate();
// ---------------------------------------------------------------------------------

};

}

#endif
