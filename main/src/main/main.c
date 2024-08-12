/*
 *
 *  Main program file.
 *
 */

#include <stdio.h>
#include <stdint.h>

#include "windowSDL2.h"
#include "windowGl.h"
#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

SDL_Window* testWindow()
{
    const char* title = "Test Window";
    int winPosX = SDL_WINDOWPOS_CENTERED;
    int winPosY = SDL_WINDOWPOS_CENTERED;
    int winWidth = 960;
    int winHeight = 540;
    Uint32 winIntFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

    SDL_GLContext context;
    SDL_Window* window = createMainWindow(title, winPosX, winPosY, winWidth, winHeight, winIntFlags);

    if (!window) {
        return NULL;
    }

    context = initGLAD2(window);
    if (!context) {
        destroySDL2Window(window);
        return NULL;
    }

    // Here you could perform additional operations on the window, such as a brief display test
    SDL_Delay(2000);

    destroyGLContext(context);
    destroySDL2Window(window);

    return window;
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        fprintf(stderr, "SDL Initialization error: %s\n", SDL_GetError());
        return 1;
    }

    if (!testWindow()) {
        SDL_Quit();
        return 1;
    }

    SDL_Quit();

    return 0;
}