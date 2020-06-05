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

#include <map>
#include <string>
#include <vector>

namespace AK
{

typedef std::vector<Widget *> WidgetChild;

class Widget : public BorderedImage, protected Location
{
    friend class WidgetManager;

    public:

        enum class WidgetAttribute
        {
            WIDTH,
            HEIGHT,
            PROPORTION,
            X,
            Y,
            PADDING,
            LAYOUT,
            ALIGN,
            TEXT,
            PATH,
            VISIBLE,
            FOCUSABLE,
            COUNT
        };

    private:

        bool g_visible;
        bool g_focusable;
        bool g_focused;

        std::string g_id;

        WidgetChild g_children;

        std::map<WidgetAttribute, std::string> g_attribute;

    public:

// -----------------------------------------------------------
        virtual void beforeAdd();
        virtual void beforeRender();
        virtual std::string getTypeName() = 0;
// -----------------------------------------------------------
        void setVisible(bool vis) { g_visible = vis; }
        void setFocusable(bool focus) { g_focusable = focus; }
        void setFocused(bool focus) { g_focused = focus; }   
// -----------------------------------------------------------

};

}

#endif
 
