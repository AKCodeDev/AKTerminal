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
    
// --------------------------------------------
        Location(int set_x = 0, int set_y = 0);
// --------------------------------------------

};

struct Size
{
        int width;
        int height;

// -------------------------------------------------
        Size(int set_width = 0, int set_height = 0);
// -------------------------------------------------

};

struct Area : Location, Size
{

// ------------------------------------------------
        Area(Location set_location, Size set_size);
// ------------------------------------------------
        bool ifInside(Location point);
        bool ifOverlay(Area area);
// ------------------------------------------------
        int getWidth() const { return width; }
        int getHeight() const { return height; }
// ------------------------------------------------

};

template<class Child>
class Matrix : protected Size
{
        protected:

                Child ** matrix;

        public:
// -------------------------------------------------------------------------------
                Matrix(int set_width = 1, int set_height = 1);
                ~Matrix() { delete[] matrix };
// -------------------------------------------------------------------------------
                initMatrix();
// -------------------------------------------------------------------------------
                virtual void setElement(Child set_element, Location set_location);
                virtual void set(Matrix<Child> set_matrix, Location set_location);
// -------------------------------------------------------------------------------
                Child getElement(Location from_location);
                Matrix<Child> get(Area from_area);
// -------------------------------------------------------------------------------
        
};

}

#endif 
