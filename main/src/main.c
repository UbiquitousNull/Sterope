/*
 *
 *  Main program file.
 *
 */

#include <stdio.h>
#include <stdint.h>

#include "window.h"
#include "SDL.h"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Initialization error: %s\n", SDL_GetError());
        return 1;
    }

    testWindow();

    SDL_Quit();

    return 0;
}