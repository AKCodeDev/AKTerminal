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

#include "widget/widget.hpp"

#include "io/output_manager.hpp"

namespace AK
{

void Widget::add(Location place, int w, int h)
{
    setWidth(w);
    setHeight(h);

    initImage(w, h);

    move(place);
}

void Widget::render()
{
    if(g_has_image)
    {
        OutputManager::g_manager->setImage(* this, g_location);
    }
}

void Widget::setImage(Image img)
{
    Area a1(makeLocation(0, 0), makeLocation(g_border.left, g_border.top));
    setStretchedImage(img.getImageFromArea(a1), a1);
    Area a2(makeLocation(g_border.left, 0), makeLocation(g_width - g_border.right, g_border.top));
    setStretchedImage(img.getImageFromArea(a2), a2);
    Area a3(makeLocation(g_width - g_border.right, 0), makeLocation(g_width, g_border.top));
    setStretchedImage(img.getImageFromArea(a3), a3);
    Area a4(makeLocation(0, g_border.top), makeLocation(g_border.left, g_height - g_border.bottom));
    setStretchedImage(img.getImageFromArea(a4), a4);
    Area a5(makeLocation(g_border.left, g_border.top), makeLocation(g_border.left, g_height - g_border.bottom));
    setStretchedImage(img.getImageFromArea(a5), a5);
    Area a6(makeLocation(g_width - g_border.right, g_border.top), makeLocation(g_border.left, g_height - g_border.bottom));
    setStretchedImage(img.getImageFromArea(a6), a6);
    Area a7(makeLocation(0, g_height - g_border.bottom), makeLocation(g_border.left, g_height));
    setStretchedImage(img.getImageFromArea(a7), a7);
    Area a8(makeLocation(g_border.left, g_height - g_border.bottom), makeLocation(g_border.left, g_height));
    setStretchedImage(img.getImageFromArea(a8), a8);
    Area a9(makeLocation(g_width - g_border.right, g_height - g_border.bottom), makeLocation(g_border.left, g_height));
    setStretchedImage(img.getImageFromArea(a9), a9);
}

}
