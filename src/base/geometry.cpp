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

Matrix::Matrix(int set_width = 0, int set_height = 0)
{
    width = set_width;
    height = set_height;
}

void Matrix::initMatrix()
{
    matrix = new Child * [width];
    for(int i = 0; i < width; i ++)
        matrix[i] = new Child[height];
}

void Matrix::setElement(Child set_element, Location set_location)
{
    if(set_location.x < 0 || set_location.x >= width)
        return;
        
    if(set_location.y < 0 || set_location.y >= height)
        return;
            
    matrix[set_location.x][set_location.y] = set_element;
}

void Matrix::set(Matrix<Child> set_matrix, Location set_location)
{
    for(int i = 0; i < set_matrix.width; i ++)
        for(int j = 0; j < set_matrix.height; j ++) 
            setElement(set_matrix.matrix[i][j], Location(i + set_location.x, j + set_location.y));
}

Child Matrix::getElement(Location from_location)
{
    bool outside = from_location.x < 0 || from_location >= width
        || from_location.y < 0 || from_location >= height;
    tryError(outside, "Bad location in Matrix::getElement");
    
    return matrix[from_location.x][from_location.y];
}

Matrix<Child> Matrix::get(Area from_area)
{
    Matrix<Child> ret(from_area);

    for(int i = 0; i < from_area.width; i ++)
    {
        if(i + from_area.x < 0 || i + from_area.x >= width)
            continue;
        
        for(int j = 0; j < from_area.height; j ++)
        {
            if(j + from_area.y < 0 || i + from_area.y >= height)
                continue;
            
            ret.set(matrix[i + from_area.x][j + from_area.y], Location(i, j));
        }
    }

    return ret;
}

Area::Area(Location set_location, Size set_size)
{
    x = set_location.x;
    y = set_location.y;
    width = set_size.width;
    height = set_size.height;
}

bool Area::ifInside(Location point)
{
    bool x_inside = point.x >= x && point.x <= x + width;
    bool y_inside = point.y >= y && point.y <= y + height;
    return x_inside && y_inside;
}

bool Area::ifOverlay(Area area)
{
    bool x_inside = x + width > area.x && area.x + area.width > x;
    bool y_inside = y + height > area.y && area.y + area.height > y;
    return x_inside && y_inside;
}

}