/*
 *
 *  Main program file.
 *
 * This program currently does not run as it doesn't complete the requirements for a windows application.
 *
 */

#include <stdio.h>
#include <stdint.h>

#include "utils.h"
#include "windowSDL2.h"
#include "windowGl.h"
#include "input.h"
#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"
#include "SDL_keyboard.h"

WINDOW r = {0};
ControlsK controls_k = {0};
ControlsM controls_m = {0};

void shutdownMain(SDL_GLContext context, SDL_Window* window)
{
	destroyGLContext(context);
	destroySDL2Window(window);
	SDL_Quit();
}

void shutdownTotal()
{
    shutdownMain(r.context, r.window);
}

WINDOW testWindow()
{
    const char* title = "Test Window";
    int winPosX = SDL_WINDOWPOS_CENTERED;
    int winPosY = SDL_WINDOWPOS_CENTERED;
    int winWidth = 960;
    int winHeight = 540;
    Uint32 winIntFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

    r.window = createMainWindow(title, winPosX, winPosY, winWidth, winHeight, winIntFlags);

    if (!r.window)
    {
        return NULL_DETAILS;
    }

    r.context = initGLAD2(r.window);
    if (!r.context)
    {
        destroySDL2Window(r.window);
        return NULL_DETAILS;
    }

    // Here you could perform additional operations on the window, such as a brief display test
    // SDL_Delay(2000);

    // destroyGLContext(context);
    // destroySDL2Window(window);

    return r;
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        FATAL_ERR("SDL Initialization error: %s\n", SDL_GetError());
        return 0;
    }

    r.valid = 1;
    r = testWindow();

    SDL_Window* window = r.window;
    if (!r.window)
    {
        SDL_Quit();
        return 0;
    }

    //parse_ini_file("defaultControls.ini", &controls_k, &controls_m);

    SDL_Event event;
    int running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
            {
                // Handle escape

                shutdownTotal();
            }
        }
    }

    shutdownTotal();

    return 0;
}

#ifdef _WIN32
#include <windows.h>
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    return main(__argc, __argv);
}    
#endif