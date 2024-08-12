/*
 *
 *  Window management program file.
 *
 */

#include <stdio.h>
#include <stdint.h>

#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

#include "windowGl.h"

SDL_Window* createMainWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, Uint32 winFlags)
{    
    SDL_Window* windowMain = SDL_CreateWindow(title, winPosX, winPosY, winWidth, winHeight, winFlags);

    if (!windowMain) {
        printf("Window creation error! SDL Error: %s\n", SDL_GetError());
        return NULL;
    }

    return windowMain;
}

void destroySDL2Window(SDL_Window* window)
{
    SDL_DestroyWindow(window);
}