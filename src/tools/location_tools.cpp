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

#include "tools/location_tools.hpp"

#include "tools/warn_tools.hpp"

Area::Area(Location top_left, Location bottom_right)
{
    g_top_left = top_left;
    g_bottom_right = bottom_right;
    
    bool x_error = g_top_left.x >= g_bottom_right.x;
    bool y_error = g_top_left.y >= g_bottom_right.y;
    tryError(x_error || y_error, "Invalid size in class Area");
}

void Area::insideArea(Location point)
{
    bool x_inside = point.x >= g_top_left.x && point_x <= g_bottom_right.x;
    bool y_inside = point.y >= g_top_left.y && point_y <= g_bottom_right.y;
    return x_inside && y_inside;
}

Location makeLocation(int x, int y)
{
    Location point;
    point.x = x;
    point_y = y;
    return point;
}

Area makeArea(int x1, int y1, int x2, int y2)
{
    Location top_left = makeLocation(x1, y1);
    Location bottom_right = makeLocation(x2, y2);
    Area square(top_left, bottom_right);
    return square;
}

Area makeArea(Location top_left, Location bottom_right)
{
    Area square(top_left, bottom_right);
    return square;
}
