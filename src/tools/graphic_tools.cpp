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

Image::Image(int width, int height)
{
    g_width = width;
    g_height = height;

    initImage(width, height);
}

Image::~Image()
{
    delete g_image;
}

void initImage(int width, int height)
{
    g_image = new Pixel*[width];
    for(int i = 0; i < width; i ++)
    {
        g_image[i] = new Pixel[height];
    }
}

void Image::setImage(Image set_image, Location set_location)
{
    for(int i = 0; i < set_image.getWidth(); i ++)
    {
        if(i + set_location.x < 0 || i + set_location.x >= g_width)
        {
            continue;
        }
        
        for(int j = 0; j < set_image.getHeight(); j ++)
        {
            if(j + set_location.y < 0 || i + set_location.y >= g_height)
            {
                continue;
            }
            
            g_image[i + set_location.x][j + set_location.y] = set_image.g_image[i][j];
        }
    }
}

void Image::setStretchedImage(Image set_image, Area set_area)
{
    for(int i = 0; i < set_area.getWidth(); i ++)
    {
        if(i + set_area.g_top_left.x < 0 || i + set_area.g_top_left.x >= g_width)
        {
            continue;
        }
        
        for(int j = 0; j < set_area.getHeight(); j ++)
        {
            if(j + set_area.g_top_left.y < 0 || i + set_area.g_top_left.y >= g_height)
            {
                continue;
            }
            
            g_image[i + set_area.g_top_left.x][j + set_area.g_top_left.y] = 
                set_image.g_image[i % set_area.getWidth()][j % set_area.getHeight()];
        }
    }
}

Image Image::getImageFromArea(Area get_area)
{
    Image ret;

    for(int i = 0; i < get_area.getWidth(); i ++)
    {
        if(i + get_area.g_top_left.x < 0 || i + get_area.g_top_left.x >= g_width)
        {
            continue;
        }
        
        for(int j = 0; j < get_area.getHeight(); j ++)
        {
            if(j + get_area.g_top_left.y < 0 || i + get_area.g_top_left.y >= g_height)
            {
                continue;
            }
            
            ret[i][j] = set_image.g_image[i + get_area.g_top_left.x][j + get_area.g_top_left.y];
        }
    }

    return ret;
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
