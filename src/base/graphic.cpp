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

Pixel::Pixel(Color set_foreground = Color::WHITE, Color set_background = Color::BLACK, char set_character = ' ')
{
    foreground = set_foreground;
    background = set_background;
    character = set_character;
}

void Pixel::operator= (const Pixel & set_pixel)
{
    switch(set_pixel.background)
    {
        case Color::REVERSE:
            background = reverseColor(background);
            break;
        case Color::ALPHA:
            break;
        default:
            background = set_pixel.background;
    }

    switch(set_pixel.foreground)
    {
        case Color::REVERSE:
            foreground = reverseColor(foreground);
            break;
        case Color::ALPHA:
            break;
        default:
            foreground = set_pixel.foreground;
    }

    if(set_pixel.foreground != Color::ALPHA && set_pixel.foreground != Color::REVERSE)
    {
        character = set_pixel.character;
    }
}

Image::Image(AKML image_file)
{
    width = std::atoi(image_file.get("width").c_str());
    height = std::atoi(image_file.get("height").c_str());
    initMatrix();

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
                break;

            if(f != '\n' || f != EOF)
                foreground_str >> f;
            else
                f = 'w';

            if(b != '\n' || b != EOF)
                background_str >> b;
            else
                b = 'b';
            
            matrix[row][column] = Pixel(charToColor(b), charToColor(f), c);
        }
        if(c == EOF)
        {
            return;
        }
    }
}

void Image::setStretched(Image set_image, Area set_area)
{
    for(int i = 0; i < set_area.width; i ++)
        for(int j = 0; j < set_area.height; j ++)
            matrix[i + set_area.x][j + set_area.y] = 
                set_image.matrix[i % set_area.width][j % set_area.height];
}

void BorderedImage::set(Image img)
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
