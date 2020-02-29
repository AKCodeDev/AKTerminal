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

#include "base/geometry.hpp"

#include "tools/warn_tools.hpp"

namespace AK
{

Location::Location(int set_x = 0, int set_y = 0)
{
    x = set_x;
    y = set_y;
}

Size::Size(int set_width = 0, int set_height = 0)
{
    width = set_width;
    height = set_height;
}

Area::Area(Location set_location, Size set_size)
{
    x = set_location.x;
    y = set_location.y;
    width = set_size.width;
    height = set_size.height;
}

bool Area::insideArea(Location point)
{
    bool x_inside = point.x >= x && point.x <= x + width;
    bool y_inside = point.y >= y && point.y <= y + height;
    return x_inside && y_inside;
}

}