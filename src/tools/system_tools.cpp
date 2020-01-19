#include "tools/system_tools.hpp"

#ifdef _WIN32
    #include <windows.h>
#elif __unix__
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

}
