#ifndef WINDOWGL_H
#define WINDOWGL_H

#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include "SDL.h"
#include "SDL_video.h"

SDL_GLContext initGLAD2(SDL_Window* window);

void destroyGLContext(SDL_GLContext context);

#endif // WINDOWGL_H