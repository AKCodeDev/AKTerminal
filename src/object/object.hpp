/*
AKTerminal - A convenient game engine for terminal games
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

        enum class Event
        {
            CREATE,
            DESTROY,
            COLLIDE,
            KEY,
            KEYPRESSED,
            KEYRELEASED,
            MOUSE,
            MOUSEIN,
            MOUSEOUT,
            GLOBALMOUSE,
            OUTOFBORDER,
            COUNT
        };

    private:

        Location g_location;

    public:

        virtual void ifGlobalEvent(Event event);

        virtual std::string getTypeName() = 0;
        
        void move(Direction direction);
        void moveToLocation(Location location);
        void jumpToLocation(Location location);

        Object * ObjectCollided(std::string typename);
        Object * ObjectAtPlace(std::string typename, Location location);

        void startFollowPath(Path path);
        void stopFollowPath();

};

}

#endif
