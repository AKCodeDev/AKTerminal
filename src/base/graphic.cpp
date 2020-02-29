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

#include "base/graphic.hpp"

#include <cstdlib>
#include <sstream>

namespace AK
{

Pixel::Pixel(Color set_foreground = Color::DEFAULT, Color set_background = Color::DEFAULT, char set_character = ' ')
{
    foreground = set_foreground;
    background = set_background;
    character = set_character;
}

Image::Image(AKML image_file)
{
    Size size(std::atoi(image_file.get("width").c_str()), std::atoi(image_file.get("height").c_str()));
    initImage(size);

    std::stringstream char_str;
    char_str << image_file.get("image");
    std::stringstream foreground_str;
    foreground_str << image_file.get("foreground");
    std::stringstream background_str;
    background_str << image_file.get("background");

    char c, f, b;

    for(int row = 0; ; row ++)
    {
        for(int column = 0; ; column ++)
        {
            char_str >> c;
            if(c == '\n' || c == EOF)
            {
                break;
            }
            if(f != '\n' || f != EOF)
            {
                foreground_str >> f;
            }
            else
            {
                f = 'd';
            }
            if(b != '\n' || b != EOF)
            {
                background_str >> b;
            }
            else
            {
                b = 'd';
            }
            
            g_image[row][column] = Pixel(charToColor(b), charToColor(f), c);
        }
        if(c == EOF)
        {
            return;
        }
    }
}

Image::Image(Size set_size = Size())
{
    initImage(set_size);
}

void Image::initImage(Size set_size)
{
    g_image = new Pixel * [set_size.width];
    for(int i = 0; i < set_size.width; i ++)
    {
        g_image[i] = new Pixel[set_size.height];
    }
}

void Image::setImage(Image set_image, Location set_location)
{
    for(int i = 0; i < set_image.width; i ++)
    {
        if(i + set_location.x < 0 || i + set_location.x >= width)
        {
            continue;
        }
        
        for(int j = 0; j < set_image.height; j ++)
        {
            if(j + set_location.y < 0 || i + set_location.y >= height)
            {
                continue;
            }
            
            g_image[i + set_location.x][j + set_location.y] = set_image.g_image[i][j];
        }
    }
}

void Image::setStretchedImage(Image set_image, Area set_area)
{
    for(int i = 0; i < set_area.width; i ++)
    {
        if(i + set_area.x < 0 || i + set_area.x >= width)
        {
            continue;
        }
        
        for(int j = 0; j < set_area.height; j ++)
        {
            if(j + set_area.y < 0 || i + set_area.y >= height)
            {
                continue;
            }
            
            g_image[i + set_area.x][j + set_area.y] = 
                set_image.g_image[i % set_area.width][j % set_area.height];
        }
    }
}

Image Image::getImageFromArea(Area get_area)
{
    Image ret(get_area);

    for(int i = 0; i < get_area.width; i ++)
    {
        if(i + get_area.x < 0 || i + get_area.x >= width)
        {
            continue;
        }
        
        for(int j = 0; j < get_area.height; j ++)
        {
            if(j + get_area.y < 0 || i + get_area.y >= height)
            {
                continue;
            }
            
            ret.g_image[i][j] = g_image[i + get_area.x][j + get_area.y];
        }
    }

    return ret;
}

void Image::setPixel(Pixel set_pixel, Location set_location)
{
    if(set_location.x < 0 || set_location.y < 0 || set_location.x > width || set_location.y > height)
    {
        return;
    }
    g_image[set_location.x][set_location.y] = set_pixel;
}

void BorderedImage::setBorderedImage(Image img)
{
    int center_width = width - g_border.left - g_border.right;
    int center_height = height - g_border.top - g_border.bottom;

    Area a1(Location(0, 0), Size(g_border.left, g_border.top));
    setStretchedImage(img.getImageFromArea(a1), a1);
    Area a2(Location(g_border.left, 0), Size(center_width , g_border.top));
    setStretchedImage(img.getImageFromArea(a2), a2);
    Area a3(Location(width - g_border.right, 0), Size(g_border.right, g_border.top));
    setStretchedImage(img.getImageFromArea(a3), a3);
    Area a4(Location(0, g_border.top), Size(g_border.left, center_height));
    setStretchedImage(img.getImageFromArea(a4), a4);
    Area a5(Location(g_border.left, g_border.top), Size(center_height, center_height));
    setStretchedImage(img.getImageFromArea(a5), a5);
    Area a6(Location(width - g_border.right, g_border.top), Size(g_border.right, center_height));
    setStretchedImage(img.getImageFromArea(a6), a6);
    Area a7(Location(0, height - g_border.bottom), Size(g_border.left, g_border.bottom));
    setStretchedImage(img.getImageFromArea(a7), a7);
    Area a8(Location(g_border.left, height - g_border.bottom), Size(center_height, g_border.bottom));
    setStretchedImage(img.getImageFromArea(a8), a8);
    Area a9(Location(width - g_border.right, height - g_border.bottom), Size(g_border.right, g_border.bottom));
    setStretchedImage(img.getImageFromArea(a9), a9);
}

}
