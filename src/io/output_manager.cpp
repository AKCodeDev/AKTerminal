#include "tools/system_tools.hpp"

#include <iostream>

void OutputManager::printPixelColor(OutputManager::Pixel pixel_color)
{
    // Foreground
    switch(pixel_color.foreground)
    {
        case Color::RED:
            // Print red
            #ifdef _WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_INTENSITY | FOREGROUND_RED);
            #elif __unix__
                std::cout << "\033[31m";
            #endif
            break;
        case Color::YELLOW:
            // Print yellow
            #ifdef _WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
            #elif __unix__
                std::cout << "\033[32m";
            #endif
            break;
        case Color::GREEN:
            // Print green
            #ifdef _WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            #elif __unix__
                std::cout << "\033[33m";
            #endif
            break;
        case Color::CYAN:
            // Print cyan
            #ifdef _WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            #elif __unix__
                std::cout << "\033[36m";
            #endif
            break;
        case Color::BLUE:
            // Print blue
            #ifdef _WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            #elif __unix__
                std::cout << "\033[34m";
            #endif
            break;
        case Color::MAGENTA:
            // Print magenta
            #ifdef _WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
            #elif __unix__
                std::cout << "\033[35m";
            #endif
            break;
        case Color::DEFAULT:
            // Print default
            #ifdef _WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_INTENSITY);
            #elif __unix__
                std::cout << "\033[0m";
            #endif
            break;
    }
}

OutputManager::OutputManager(int width, int height, float rate)
{
    g_rate = rate;
    if(g_rate < 0.0f)
    {
        g_rate = DEFAULT_RATE;
    }
    
    g_width = width;
    g_height = height;
    
    g_output = (Pixel**)std::calloc(width, sizeof(Pixel*));
    for(int i = 0; i < height; i ++)
    {
        g_output[i] = (Pixel*)std::calloc(height, sizeof(Pixel));
    }
}

void OutputManager::setPixel(Pixel set_pixel, int x, int y)
{
    OutputManager::g_output[x][y] = set_pixel;
}

void OutputManager::updateOutput()
{
    for(int i = 0; i < OutputManager::g_width; i ++)
    {
        for(int j = 0; j < OutputManager::g_height; j ++)
        {
            printPixelColor(OutputManager::g_output[i][j]);
            std::cout << OutputManager::g_output[i][j].character;
        }
        std::cout << std::endl;
    }
    
    sleepFunc(1.0f / g_rate);
    
    clearFunc();
} 
