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

#include "tools/graphic_tools.hpp"

namespace AK
{

Image::Image(int width, int height, float rate = DEFAULT_RATE)
{
    g_width = width;
    g_height = height;
    
    g_image = new Pixel*[width];
    for(int i = 0; i < width; i ++)
    {
        g_image[i] = new Pixel[height];
    }
}

Image::~Image()
{
    delete g_image;
}

void Image::setPixel(Pixel set_pixel, Location set_location)
{
    if(set_location.x < 0 || set_location.y < 0)
    {
        return;
    }
    Image::g_image[set_location.x][set_location.y] = set_pixel;
} 

}
