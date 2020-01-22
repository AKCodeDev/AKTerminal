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

#ifndef OUTPUT_MANAGER
#define OUTPUT_MANAGER

#include "tools/color_tools.hpp"
#include "manager_template.hpp"

namespace AK
{

class OutputManager : public Manager
{
    public:
    
        struct Pixel
        {
            Color foreground;
            Color background;
            char character;
        };
        
    private:
        
        Pixel ** g_output;
        
        int g_width;
        int g_height;
        
        #define DEFAULT_RATE 6.0f
        float g_rate;
        
    public:
    
// ------------------------------------------------------
        OutputManager(int width, int height, float rate);
        ~OutputManager();
// ------------------------------------------------------
        int getWidth() const { return g_width; }
        int getHeight() const { return g_height; }
// ------------------------------------------------------
        void setPixel(Pixel set_pixel, int x, int y);
// ------------------------------------------------------
        void onUpdate();
// ------------------------------------------------------

}; // OutputManager

}

#endif
