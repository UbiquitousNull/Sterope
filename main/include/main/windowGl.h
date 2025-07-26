#ifndef WINDOWGL_H
#define WINDOWGL_H

    /*
     *
     *  Header file for window.c
     * 
     *  This file is meant for management of program windows GLAD2 instance
     *
     */

#include <KHR/khrplatform.h>
#include <glad/gl.h>
#include "windowSDL2.h"

void destroyGLContext(SDL_GLContext context);

SDL_GLContext initialiseGLAD2(SDL_Window* window);

#endif // WINDOWGL_H