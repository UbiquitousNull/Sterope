#ifndef WINDOWGL_H
#define WINDOWGL_H

    /*
     *
     *  Header file for window.c
     * 
     *  This file is meant for management of program windows GLAD2 instance
     *
     */

#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

void destroyGLContext(SDL_GLContext context);

SDL_GLContext initGLAD2(SDL_Window* window);

#endif // WINDOWGL_H