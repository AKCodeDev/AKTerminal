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

#include "tools/color_tools.hpp"
#include "tools/geometry_tools.hpp"

namespace AK
{

struct Pixel
{
    Color foreground;
    Color background;
    char character;
};

class Image
{
    private:
        
        int g_width = 0;
        int g_height = 0;
        
    protected:
        
        Pixel ** g_image;
        
    public:
    
// -------------------------------------------------------------------------------------------------------------------
        Image(int width, int height);
        ~Image();
// -------------------------------------------------------------------------------------------------------------------
        void initImage(int width, int height);
// -------------------------------------------------------------------------------------------------------------------
        int getWidth() const { return g_width; }
        int getHeight() const { return g_height; }
// -------------------------------------------------------------------------------------------------------------------
        void setImage(Image set_image, Location set_location);
        void setStretchedImage(Image set_image, Area set_area);
        Image getImageFromArea(Area get_area);
// -------------------------------------------------------------------------------------------------------------------
        void setPixel(Pixel set_pixel, Location set_location);
// -------------------------------------------------------------------------------------------------------------------
        Area getArea(Location loc) const { return makeArea(loc.x, loc.y, loc.x + g_width - 1, loc.y + g_height - 1); }
// -------------------------------------------------------------------------------------------------------------------
        
};

}

#endif
