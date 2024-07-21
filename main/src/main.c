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
    /*
     *
     */

    initSDL(SDL_INIT_VIDEO);
    testWindow();
    quitSDL();

     return 0;
}