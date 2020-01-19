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

OutputManager::OutputManager(int width, int height, float rate = DEFAULT_RATE)
{
    g_rate = rate;
    if(g_rate < 0.0f)
    {
        g_rate = DEFAULT_RATE;
    }
    
    g_width = width;
    g_height = height;
    
    g_output = new Pixel*[width];
    for(int i = 0; i < width; i ++)
    {
        g_output[i] = new Pixel[height];
    }
}

OutputManager::~OutputManager()
{
    delete g_output;
}

void OutputManager::setPixel(Pixel set_pixel, int x, int y)
{
    OutputManager::g_output[x][y] = set_pixel;
}

void OutputManager::updateOutput()
{
    for(int i = 0; i < OutputManager::g_width; i ++)
    {
        for(int j = 0; j < OutputManager::g_height; j ++)
        {
            printForegroundColor(OutputManager::g_output[i][j].foreground);
            printBackgroundColor(OutputManager::g_output[i][j].background);
            
            std::cout << OutputManager::g_output[i][j].character;
        }
        
        resetColor();
        
        std::cout << std::endl;
    }
    
    sleepFunc(1.0f / g_rate);
    
    clearFunc();
}

}
