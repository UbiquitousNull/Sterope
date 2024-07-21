/*
 *
 *  Window management program file.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <utils.h>

/*
 *  For SDL2 headers that I haven't included into the project yet.
 */

#include "SDL.h"
#include "SDL_video.h"


void createMainWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, Uint32 winFlags)
{
    /*
     *
     */
    
    SDL_Window* windowMain = SDL_CreateWindow(title, winPosX, winPosY, winWidth, winHeight, winFlags);

    if (!windowMain) {
        printf("Window creation error! SDL Error: %s\n", SDL_GetError());
    }else
    {
        SDL_Delay(2000);
        SDL_DestroyWindow(windowMain);
    }
}

void testWindow()
{
    const char* title = "Test Window";
    int winPosX = SDL_WINDOWPOS_UNDEFINED;
    int winPosY = SDL_WINDOWPOS_UNDEFINED;
    int winWidth = 640;
    int winHeight = 480;
    Uint32 winIntFlags = SDL_WINDOW_RESIZABLE;

    createMainWindow(title, winPosX, winPosY, winWidth, winHeight, winIntFlags);
}

void initSDL(Uint32 initFlags)
{
    /*
     *
     */

    SDL_Init(initFlags);
}

void quitSDL()
{
    /*
     *
     */

    SDL_Quit();
}

// int main() 
// {
//     /*
//      *
//      */

//     initSDL(SDL_INIT_VIDEO);
//     testWindow();
//     quitSDL();

//     return 0;    
// }
