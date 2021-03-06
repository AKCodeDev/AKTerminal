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

#include "io/output_manager.hpp"

#include "tools/system_tools.hpp"

#include <iostream>

namespace AK
{

void OutputManager::printPixel(Pixel print_pixel)
{
    printForegroundColor(print_pixel.foreground);
    printBackgroundColor(print_pixel.background);
            
    std::cout << print_pixel.character;
}

OutputManager::OutputManager(Size size, float rate = DEFAULT_RATE)
{
    g_rate = rate;
    if(g_rate < 0.0f)
    {
        g_rate = DEFAULT_RATE;
    }
    
    width = width;
    height = height;
    
    g_image = new Pixel*[width];
    for(int i = 0; i < width; i ++)
    {
        g_image[i] = new Pixel[height];
    }
}

void OutputManager::onUpdate()
{
    for(int i = 0; i < width; i ++)
    {
        for(int j = 0; j < height; j ++)
        {
            printPixel(g_image[i][j]);
        }
        
        resetColor();
        
        std::cout << std::endl;
    }
    
    sleepFunc(1.0f / g_rate);
    
    clearFunc();
}

}
