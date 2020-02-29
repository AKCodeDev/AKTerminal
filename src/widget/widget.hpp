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

#ifndef WIDGET
#define WIDGET

#include "base/geometry.hpp"
#include "base/graphic.hpp"

#include <string>

namespace AK
{

class Widget : public BorderedImage
{
    public:

        enum class WidgetAttribute
        {
            PROPORTION,
            WIDTH,
            HEIGHT,
            PADDING,
            X,
            Y,
            LAYOUT,
            ALIGN,
            TEXT,
            IMAGE,
            VISIBLE,
            FOCUSABLE,
            COUNT
        };

    private:

        bool g_visible;
        bool g_focusable;
        bool g_focused;

        Location g_location;

        std::string g_id;

    public:

// -----------------------------------------------------------
        virtual void add(Location place, Size size);
        virtual std::string getTypeName() = 0;
// -----------------------------------------------------------
        void setVisible(bool vis) { g_visible = vis; }
        void setFocusable(bool focus) { g_focusable = focus; }
        void setFocused(bool focus) { g_focused = focus; }   
// -----------------------------------------------------------
        void move(Location point) { g_location = point; }
// -----------------------------------------------------------
        void setID(std::string str) { g_id = str; }
// -----------------------------------------------------------
        bool ifVisible() const { return g_visible; }
        bool ifFocusable() const { return g_focusable; }
        bool ifFocused() const { return g_focused; }
// -----------------------------------------------------------
        Location getLocation() const { return g_location; }
// -----------------------------------------------------------
        std::string getID() const { return g_id; } 
// -----------------------------------------------------------

};

}

#endif
 
