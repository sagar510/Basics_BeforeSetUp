/*#include<stdio.h>
#include<string.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

GLuint VAO, VBO, shader;

//Vertex Shader
static const char* vshader = "								\n\
	#version 330											 \n\
	layout (location=0) in vec3 pos;						  \n\
	void main(){											   \n\
		gl_Position=vec4(pos.x,pos.y,pos.z,1.0);				\n\
	}";

//Fragment Shader
static const char* fshader = "										\n\
	#version 330						     						 \n\
	out vec4 colour;												  \n\
	void main(){													   \n\
		colour = vec4(1.0f,0.0f,0.0f,1.0f);							    \n\
	}															         \n\
";

void cubeSquare() {
	GLfloat vertex[] = {
		-1.0f,-1.0f,0.f,
		-1.0f,1.0f,0.f,
		1.0f,1.0f,0.0f,
		1.0f,-1.0f,0.f
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	glVertexAttribPointer(0,  2, GL_FLOAT, GL_FALSE,2*sizeof(GLfloat),0);

	//Unbinding
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void AddShader(GLuint theprogram, const char* shadercode, GLenum shadertype) {

	GLuint theshader = glCreateShader(shadertype);

	const GLchar* thecode[1];
	thecode[0] = shadercode;

	GLint codelength[1];
	codelength[0] = strlen(shadercode);

	glShaderSource(theshader, 1, thecode, codelength);

	glCompileShader(theshader);

	glAttachShader(theprogram, theshader);

}

void compileShaders() {

	shader = glCreateProgram();

	AddShader(shader, vshader, GL_VERTEX_SHADER);
	AddShader(shader, fshader, GL_FRAGMENT_SHADER);

	glLinkProgram(shader);
	glValidateProgram(shader);
}

void main() {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Square", NULL, NULL);

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	glewInit();

	glViewport(0, 0, 800, 800);

	cubeSquare();
	compileShaders();

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);
		glBindVertexArray(VAO);
		glDrawArrays(GL_LINE_STRIP, 0, 4);

		glBindVertexArray(0);
		glUseProgram(0);

		glfwSwapBuffers(window);
	}

}*/