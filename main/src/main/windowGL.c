/**
 * 
 *  This file is meant for management of program windows GLAD2 instance
 *
 */

#include <stdio.h>

#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
// #include "SDL_video.h"

#include "windowSDL2.h"

void destroyGLContext(SDL_GLContext context)
{
    SDL_GL_DeleteContext(context);
}

SDL_GLContext createGLContext(SDL_Window* window)
{
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext)
    {
        fprintf(stderr, "Failed to create OpenGL context: %s\n", SDL_GetError());
        destroySDL2Window(window);
        SDL_Quit();
        return NULL;
    }

    if (!gladLoaderLoadGL())
    {
        fprintf(stderr, "Failed to initialize GLAD\n");
        destroyGLContext(glContext);
        destroySDL2Window(window);
        SDL_Quit();
        return NULL;
    }

    return glContext;
}
