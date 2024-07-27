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

void createWindow(const char* title, int winPosX, int winPosY, int winWidth, int winHeight, uint32_t winFlags);

void menuTest();

void testWindow();

#endif // MAIN_H