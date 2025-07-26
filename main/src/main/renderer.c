#include "main.h"

void renderBasicTest(SDL_Window* window)
{
	// Set up a simple triangle for testing
	float testVertices[] = {
		-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
	};

	// Generate and bind a Vertex Buffer Object (VBO)
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(testVertices), testVertices, GL_STATIC_DRAW);

	// Create vertex shader
	const char *testVertexShaderSource = 
	"#version 460 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

	// Compile and error check vertex shader
	unsigned int testVertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(testVertexShader, 1, &testVertexShaderSource, NULL);
	glCompileShader(testVertexShader);
	int  success;
	char infoLog[512];
	glGetShaderiv(testVertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(testVertexShader, 512, NULL, infoLog);
		FATAL_ERR("Vertex Shader Compilation Error: %s\n", infoLog);
	}

	// Create fragment shader
	const char *testFragmentShaderSource =
	"#version 460 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
		"   FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
	"}\0";

	// Compile and error check fragment shader
	unsigned int testFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(testFragmentShader, 1, &testFragmentShaderSource, NULL);
	glCompileShader(testFragmentShader);
	glGetShaderiv(testFragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(testFragmentShader, 512, NULL, infoLog);
		FATAL_ERR("Fragment Shader Compilation Error: %s\n", infoLog);
	}

	// Create and error check shader program
	unsigned int testShaderProgram = glCreateProgram();
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glUseProgram(testShaderProgram);

	// to implement a basic render loop

	// SDL_Delay(16);  // Roughly 60 FPS (1000ms / 60 ≈ 16ms per frame)
}