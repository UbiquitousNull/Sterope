/**
 *
 *  Main program file.
 *
 * This program runs but only displays a test OpenGL tri-coloured triangle.
 *
 */

#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "utils.h"
#include "windowSDL2.h"
#include "windowGl.h"
#include "input.h"

WINDOW r = {0};
ControlsK controls_k = {0};
ControlsM controls_m = {0};

void shutdownMain(SDL_GLContext context, SDL_Window* window)
{
	destroyGLContext(context);
	destroySDL2Window(window);
	SDL_Quit();
    exit(0);
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
        FATAL_ERR("Failed to create SDL2 window: %s\n", SDL_GetError());
        return NULL_DETAILS;
    }

    r.context = createGLContext(r.window);
    if (!r.context)
    {
        FATAL_ERR("Failed to initialize OpenGL context: %s\n", SDL_GetError());
        destroySDL2Window(r.window);
        return NULL_DETAILS;
    }

    // Here you could perform additional operations on the window, such as a brief display test
    // SDL_Delay(2000);
    // destroySDL2Window(window);

    return r;
}

int main(int argc, char *argv[])
{
    // int result = MessageBoxA(NULL, "Welcome to STEROPE!", "Welcome", MB_YESNO | MB_ICONINFORMATION);
    // if (result == IDYES)
    // {
    //     FATAL_ERR("You clicked Yes. Exiting the program.\n");
    //     return 0;
    // }
    // else if (result == IDNO)
    // {
    //     MessageBoxA(NULL, "You clicked No. Continuing with the program.\n", "Information", MB_OK | MB_ICONINFORMATION);
    // }

    SDL_SetMainReady();
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
    {
        FATAL_ERR("SDL Initialization error: %s\n", SDL_GetError());
        return 0;
    }

    if(SDL_InitSubSystem(SDL_INIT_EVENTS) != 0)
    {
        FATAL_ERR("SDL Events Initialization error: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    r.valid = 1;
    r = testWindow();
    if (!r.window)
    {
        SDL_Quit();
        return 0;
    }
    SDL_Window* window = r.window;

    // parse_ini_file("defaultControls.ini", &controls_k, &controls_m);

    SDL_Event event;
    int running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
            {
                // Handle escape
                running = 0;
                shutdownTotal();
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.mod == SDLK_LSHIFT && event.key.keysym.sym == SDLK_n)
            {
                
            }
        }
        renderBasicTest(r.window);
    }
    FATAL_ERR("Exiting main loop.\n");

    shutdownTotal();

    return 0;
}

#ifdef _WIN32
#include <windows.h>
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    return main(__argc, __argv);
}    
#endif