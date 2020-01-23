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
};

class Area
{
    public:
    
        Location g_top_left;
        Location g_bottom_right;

// --------------------------------------------------------------------------
        Area(Location top_left, Location bottom_right);
// --------------------------------------------------------------------------
        bool insideArea(Location point);
// --------------------------------------------------------------------------
        int getWidth() const { return g_bottom_right.x - g_top_left.x + 1; }
        int getHeight() const { return g_bottom_right.y - g_top_left.y + 1; }
// --------------------------------------------------------------------------

};

// --------------------------------------------------------------------------
Location makeLocation(int x, int y);
// --------------------------------------------------------------------------
Area makeArea(int x1, int y1, int x2, int y2);
// --------------------------------------------------------------------------
Area makeArea(Location top_left, Location bottom_right);
// --------------------------------------------------------------------------

}

#endif 
