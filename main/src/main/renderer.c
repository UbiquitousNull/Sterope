#include <main.h>

void renderBasicTest(SDL_Window* window)
{
    // Clear the screen with a color
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // Dark gray background
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL objects here
        // Example: Drawing a simple triangle (you would typically use shaders, VBOs, VAOs, etc.)
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); // Red
            glVertex2f(0.0f,  0.5f);    // Top
            glColor3f(0.0f, 1.0f, 0.0f); // Green
            glVertex2f(-0.5f, -0.5f);   // Bottom left
            glColor3f(0.0f, 0.0f, 1.0f); // Blue
            glVertex2f(0.5f, -0.5f);    // Bottom right
        glEnd();

        // Swap the front and back buffers
        SDL_GL_SwapWindow(window);

        SDL_Delay(16);  // Roughly 60 FPS (1000ms / 60 ≈ 16ms per frame)
}