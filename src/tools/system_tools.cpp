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

#include "tools/system_tools.hpp"

#ifdef _WIN32
	#include <conio.h>
    #include <windows.h>
#elif __unix__
	#include <iostream>
	#include <fcntl.h>
	#include <termios.h>
    #include <unistd.h>
#endif

namespace AK
{

void sleepFunc(float t)
{
#ifdef _WIN32

	Sleep(1000 * t);

#elif __unix__

	usleep(1000000 * t);

#endif
}

void clearFunc()
{
#ifdef _WIN32

	system("CLS");

#elif __unix__

	system("clear");

#endif
}

bool ifKeyboardHit()
{
#ifdef _WIN32

	return (bool)kbhit();

#elif __unix__

    struct termios oldt, newt;
    char ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    std::cin >> ch;

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return true;
    }
    return false;

#endif
}

char getKeyboardHitChar()
{
#ifdef _WIN32

	return getch();

#elif __unix__

    struct termios oldt, newt;
    char ch;
    int oldf = 0;
 
	tcgetattr(oldf, &newt);

	oldt = newt;
	cfmakeraw(&newt);
	tcsetattr(oldf, TCSANOW, &newt);

	std::cin >> ch;
	tcsetattr(oldf, TCSANOW, &oldt);

	return ch;

#endif
}

}
