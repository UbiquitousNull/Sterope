#ifndef WINDOWSDL2_H
#define WINDOWSDL2_H

    /*
     *
     *  Header file for window.c
     * 
     *  This file is meant for management of program windows SDL2 instance
     *
     */

#include <stdint.h>
#include "windowGl.h"
#include "SDL.h"
#include "SDL_video.h"

void destroySDL2Window(SDL_Window* window);

SDL_Window* createMainWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, uint32_t winFlags);

#endif // WINDOWSDL2_H