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

#ifndef LOCATION_TOOLS
#define LOCATION_TOOLS

namespace AK
{

struct Location
{
        int x;
        int y;
    
// ------------------------------------
        Location(int set_x, int set_y);
// ------------------------------------

};

struct Size
{
        int width;
        int height;

// -----------------------------------------
        Size(int set_width, int set_height);
// -----------------------------------------

};

struct Area : Location, Size
{

// ------------------------------------------------
        Area(Location set_location, Size set_size);
// ------------------------------------------------
        bool insideArea(Location point);
// ------------------------------------------------
        int getWidth() const { return width; }
        int getHeight() const { return height; }
// ------------------------------------------------

};

}

#endif 
