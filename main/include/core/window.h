#ifndef MAIN_H
#define MAIN_H

    /*
     *
     *  Header file for window.c
     * 
     *  This file is meant for management of program windows
     *
     */

#include <stdint.h>
#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

void createMainWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, uint32_t winFlags);

void initGLAD2(SDL_Window* window);

void menuTest();

SDL_Window* testWindow();

#endif // MAIN_H