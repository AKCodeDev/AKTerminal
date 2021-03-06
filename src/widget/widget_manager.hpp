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

#ifndef WIDGET_MANAGER
#define WIDGET_MANAGER

#include "base/manager.hpp"
#include "widget/widget.hpp"

namespace AK
{

class WidgetManager : public Manager<WidgetManager>
{
    private:

        WidgetChild g_all_widgets;

        void addWidget(Widget add_widget);

        void renderWidget(Widget render_widget);

    public:

        WidgetChild layAllWidgets();

        void onUpdate();

};

}

#endif
