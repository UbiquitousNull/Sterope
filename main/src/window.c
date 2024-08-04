/*
 *
 *  Window management program file.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <utils.h>

#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

void initGLAD2(SDL_Window* window)
{
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        fprintf(stderr, "Failed to create OpenGL context: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    if (!gladLoaderLoadGL()) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}

void createMainWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, Uint32 winFlags)
{    
    SDL_Window* windowMain = SDL_CreateWindow(title, winPosX, winPosY, winWidth, winHeight, winFlags);

    if (!windowMain) {
        printf("Window creation error! SDL Error: %s\n", SDL_GetError());
    }else
    {
        initGLAD2(windowMain);
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
    Uint32 winIntFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

    createMainWindow(title, winPosX, winPosY, winWidth, winHeight, winIntFlags);
}