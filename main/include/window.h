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

void createMainWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, uint32_t winFlags);

void testWindow();

void initSDL(uint32_t initFlags);

void quitSDL();


#endif // MAIN_H