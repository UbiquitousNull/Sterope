/*
 * 
 *  This file is meant for management of program windows GLAD2 instance
 *
 */

#include <stdio.h>

#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

#include "windowSDL2.h"

SDL_GLContext initGLAD2(SDL_Window* window)
{
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context)
    {
        fprintf(stderr, "Failed to create OpenGL context: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
    }

    if (!gladLoaderLoadGL())
    {
        fprintf(stderr, "Failed to initialize GLAD\n");
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
    }

    return context;
}

void destroyGLContext(SDL_GLContext context)
{
    SDL_GL_DeleteContext(context);
}