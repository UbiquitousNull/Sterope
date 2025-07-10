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

// Structures
typedef struct {
	uint8_t valid;
	SDL_GLContext context;
	SDL_Window* window;
} WINDOW;

// Macros
#define NULL_DETAILS (WINDOW){ .valid = 0 }

// Function prototypes
void shutdownMain(SDL_GLContext context, SDL_Window* window);
void shutdownTotal();

#endif // MAIN_H