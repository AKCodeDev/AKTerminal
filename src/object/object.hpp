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

#ifndef OBJECT
#define OBJECT

#include "base/graphic.hpp"

#include <string>
#include <vector>

namespace AK
{

typedef std::vector<Object *> ObjectChild;

class Object : public Image
{
    friend class ObjectManager;

    public:

        enum class Events
        {
            CREATE,
            DESTROY,
            COLLIDE,
            KEY,
            KEYPRESSED,
            KEYRELEASED,
            MOUSE,
            MOUSEENTERED,
            MOUSEOUT,
            GLOBALMOUSE,
            OUTOFBORDER,
            COUNT
        };

    private:

        Area g_collide_mask;

        Location g_location;

        Location g_center;

        Speed g_speed;

    public:

        virtual void ifGlobalEvent(Events event);

        virtual std::string getTypeName() = 0;

        void setImage(Image set_image);
        void setLocation(Location set_location);
        void setCollisionMask(Area set_mask);
        void setSpeed(Speed set_speed);
        void moveToLocation(Location location);

};

}

#endif
