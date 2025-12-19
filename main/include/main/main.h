#ifndef MAIN_H
#define MAIN_H

	/**
	 *
	 *  Header file for main.c
	 * 
	 *  I am planning to use this file to encapsulate the main functionality of the program and to be used as a single point of access.
	 *
	 */

#include <stdio.h>
#include <stdint.h>
#include "io.h"
#include "utils.h"
#include "logging.h"
#include "renderer.h"
#include "input.h"

// Structures
typedef struct {
	uint8_t			valid;
	uint8_t			alive;
	Uint32			id;
	SDL_GLContext	context;
	SDL_Window*		window;
	GLuint			vao;
	GLuint			vbo;
	GLuint			shaderProgram;
} WINDOW;

// Macros
#define NULL_DETAILS (WINDOW){0}

// Function prototypes
void shutdownMain(SDL_GLContext context, SDL_Window* window);
void shutdownTotal();

#endif // MAIN_H