/*
 *
 *  Window management program file.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <utils.h>

#include "SDL.h"
#include "SDL_video.h"


void createWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, Uint32 winFlags)
{    
    SDL_Window* windowMain = SDL_CreateWindow(title, winPosX, winPosY, winWidth, winHeight, winFlags);

    if (!windowMain) {
        printf("Window creation error! SDL Error: %s\n", SDL_GetError());
    }else
    {
        SDL_Delay(2000);
        SDL_DestroyWindow(windowMain);
    }
}

void menuTest()
{
    //
}

void testWindow()
{
    const char* title = "Test Window";
    int winPosX = SDL_WINDOWPOS_CENTERED;
    int winPosY = SDL_WINDOWPOS_CENTERED;
    int winWidth = 960;
    int winHeight = 540;
    Uint32 winIntFlags = SDL_WINDOW_RESIZABLE;

    createWindow(title, winPosX, winPosY, winWidth, winHeight, winIntFlags);
}