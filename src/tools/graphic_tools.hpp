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

#include "tools/akml_tools.hpp"
#include "tools/color_tools.hpp"
#include "tools/geometry_tools.hpp"

namespace AK
{

struct Pixel
{
        Color foreground;
        Color background;
        char character;

// -------------------------------------------------------------------------------------------------------------------
        Pixel(Color set_foreground = Color::DEFAULT, Color set_background = Color::DEFAULT, char set_character = ' ');
// -------------------------------------------------------------------------------------------------------------------

};

class Image : protected Size
{
    protected:
        
        Pixel ** g_image;
        
    public:
    
// ------------------------------------------------------------
        Image(AKML image_file);
        Image(Size set_size = Size());
        ~Image() { delete g_image; }
// ------------------------------------------------------------
        void initImage(Size set_size);
// ------------------------------------------------------------
        void setImage(Image set_image, Location set_location);
        void setStretchedImage(Image set_image, Area set_area);
        Image getImageFromArea(Area get_area);
// ------------------------------------------------------------
        void setPixel(Pixel set_pixel, Location set_location);
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

    private:

        BorderSize g_border;

    public:

// ----------------------------------------------------------------------------
        BorderedImage(AKML image_file) { setBorderedImage(Image(image_file)); }
        BorderedImage(Size set_size) { initImage(set_size); }
// ----------------------------------------------------------------------------
        void setBorderSize(BorderSize size) { g_border = size; }
// ----------------------------------------------------------------------------
        void setBorderedImage(Image img);
// ----------------------------------------------------------------------------

};

}

#endif
