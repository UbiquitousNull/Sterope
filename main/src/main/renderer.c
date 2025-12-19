#include "main.h"

void renderBasicTest(SDL_Window* window)
{
	static GLuint vao = 0;
	static GLuint vbo = 0;
	static GLuint testShaderProgram = 0;

	if(testShaderProgram == 0) {

		// Set up a simple triangle for testing
		float testVertices[] = {
			-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,
			0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f,
		};

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		// Generate and bind a Vertex Buffer Object (VBO)
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(testVertices), testVertices, GL_STATIC_DRAW);

		// Create vertex shader
		const char *tvs = 
		"#version 460 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 vColor;\n"
		"void main()\n"
		"{\n"
		"	vColor = aColor;\n"
		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\n";

		// Create fragment shader
		const char *tfs =
		"#version 460 core\n"
		"in vec3 vColor;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(vColor, 1.0);\n"
		"}\n";

		// Compile and error check vertex shader
		unsigned int testVertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(testVertexShader, 1, &tvs, NULL);
		glCompileShader(testVertexShader);
		int  success;
		char infoLog[512];
		glGetShaderiv(testVertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(testVertexShader, 512, NULL, infoLog);
			FATAL_ERR("Vertex Shader Compilation Error: %s\n", infoLog);
		}

		

		// Compile and error check fragment shader
		unsigned int testFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(testFragmentShader, 1, &tfs, NULL);
		glCompileShader(testFragmentShader);
		glGetShaderiv(testFragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(testFragmentShader, 512, NULL, infoLog);
			FATAL_ERR("Fragment Shader Compilation Error: %s\n", infoLog);
		}

		// Create and error check shader program
		testShaderProgram = glCreateProgram();
		glAttachShader(testShaderProgram, testVertexShader);
		glAttachShader(testShaderProgram, testFragmentShader);
		glLinkProgram(testShaderProgram);
		glGetProgramiv(testShaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(testShaderProgram, 512, NULL, infoLog);
			FATAL_ERR("Shader Program Linking Error: %s\n", infoLog);
		}

		// Clean up shader objects
		glDeleteShader(testVertexShader);
		glDeleteShader(testFragmentShader);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

	}

	glUseProgram(testShaderProgram);

	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	glViewport(0, 0, w, h);
	
	glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	SDL_GL_SwapWindow(window);

	// SDL_Delay(16);  // Roughly 60 FPS (1000ms / 60 ≈ 16ms per frame)
}