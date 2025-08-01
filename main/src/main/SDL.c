/*
 * 
 *  This file is meant for management of program windows SDL2 instance
 *
 */

#include <stdio.h>
#include "renderer.h"

int initialiseSDL()
{
    
}

void destroySDL2Window(SDL_Window* window)
{
    SDL_DestroyWindow(window);
}

/// @brief 
/// @param title 
/// @param winPosX 
/// @param winPosY 
/// @param winWidth 
/// @param winHeight 
/// @param winFlags 
/// @return 
SDL_Window* createMainWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, uint32_t winFlags)
{    
    SDL_Window* windowMain = SDL_CreateWindow(title, winPosX, winPosY, winWidth, winHeight, winFlags);

    if (!windowMain) {
        printf("Window creation error! SDL Error: %s\n", SDL_GetError());
        return NULL;
    }

    return windowMain;
}