#ifndef MAIN_H
#define MAIN_H

    /*
     *
     *  Header file for main.c (This might be surperfluous) Note: Nvm!
     *
     */

#include <stdio.h>
#include <stdint.h>

#include "windowSDL2.h"
#include "windowGl.h"
#include "input.h"
#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

typedef struct {
	uint8_t valid;
	SDL_GLContext context;
	SDL_Window* window;
} WINDOW;
#define NULL_DETAILS (WINDOW){ .valid = 0 }

#endif // MAIN_H