#ifndef WINDOWGL_H
#define WINDOWGL_H

    /**
     *
     *  Header file for window.c
     * 
     *  This file is meant for management of program windows GLAD2 instance
     *
     */

#include <KHR/khrplatform.h>
#include <glad/gl.h>
#include <SDL.h>

void destroyGLContext(SDL_GLContext context);

SDL_GLContext createGLContext(SDL_Window* window);

#endif // WINDOWGL_H