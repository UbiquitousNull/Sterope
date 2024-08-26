/*
 *
 *  Main program file.
 *
 */

#include <stdio.h>
#include <stdint.h>

#include "windowSDL2.h"
#include "windowGl.h"
#include "input.h"
#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

void shutdownMain(SDL_GLContext context, SDL_Window* window)
{
	destroyGLContext(context);
	destroySDL2Window(window);
	SDL_Quit();
}

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

    if (!window)
    {
        return NULL;
    }

    context = initGLAD2(window);
    if (!context)
    {
        destroySDL2Window(window);
        return NULL;
    }

    // Here you could perform additional operations on the window, such as a brief display test
    // SDL_Delay(2000);

    // destroyGLContext(context);
    // destroySDL2Window(window);

    return window;
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        fprintf(stderr, "SDL Initialization error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = testWindow();

    if (!testWindow())
    {
        SDL_Quit();
        return 1;
    }

    int running = 1;

    parse_ini_file("controls.ini", &controls_k, &controls_m);

    while (running)
    {
        SDL_Event event;

        

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_Quit) { running = 0; }
            
            if (event.key.keysym == SDLK_ESCAPE)
            {
                // Handle escape
            }
        }
    }

    shutdownMain(window);

    return 0;
}