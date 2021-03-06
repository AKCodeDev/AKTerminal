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

#ifndef GRAPHIC_TOOLS
#define GRAPHIC_TOOLS

#include "base/geometry.hpp"
#include "file/akml.hpp"
#include "tools/color_tools.hpp"

namespace AK
{

struct Pixel
{
        Color foreground;
        Color background;
        char character;

// ---------------------------------------------------------------------------------------------------------------
        Pixel(Color set_foreground = Color::WHITE, Color set_background = Color::BLACK, char set_character = ' ');
// ---------------------------------------------------------------------------------------------------------------
        void operator=(const Pixel & set_pixel);
// ---------------------------------------------------------------------------------------------------------------

};

class Image : protected Matrix<Pixel>
{    
    public:
    
// ------------------------------------------------------------
        Image(AKML image_file);
        using Matrix::Matrix();
        ~Image() { delete g_image; }
// ------------------------------------------------------------
        void setStretched(Image set_image, Area set_area);
// ------------------------------------------------------------
        
};

class BorderedImage : public Image
{
    public:

        struct BorderSize
        {
            int left;
            int right;
            int top;
            int bottom;
        };

    protected:

        BorderSize g_border;

    public:

// ----------------------------------------------------------------------------
        BorderedImage(AKML image_file) { setBorderedImage(Image(image_file)); }
        BorderedImage(Size set_size) { initImage(set_size); }
// ----------------------------------------------------------------------------
        void setBorderSize(BorderSize size) { g_border = size; }
// ----------------------------------------------------------------------------
        void set(Image img);
// ----------------------------------------------------------------------------

};

}

#endif
