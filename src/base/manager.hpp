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

#ifndef MANAGER_TEMPLATE
#define MANAGER_TEMPLATE

namespace AK
{

class BasicManager
{
	public:
	
// ---------------------------------
        virtual void onUpdate() = 0;
// ---------------------------------

};

template<class ChildManager>
class Manager : public BasicManager
{
	protected:
		
		static ChildManager * g_manager = nullptr;
		
    public:
    
// ------------------------------------------------------------
		static void create() { g_manager = new ChildManager; }
		static ChildManager * get() const { return g_manager; }
		static void destroy() { delete g_manager; }
// ------------------------------------------------------------

};

}

#endif
