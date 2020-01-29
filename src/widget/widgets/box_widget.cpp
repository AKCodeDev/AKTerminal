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

#include "widget/widgets/box_widget.hpp"

#include "io/output_manager.hpp"

void BoxWidget::add(Location place, int w, int h)
{
    setWidth(w);
    setHeight(h);

    initImage(w, h);

    move(place);
}

void BoxWidget::render()
{
    if(g_has_image)
    {
        OutputManager::g_manager->setImage(* self, g_location);
    }
}