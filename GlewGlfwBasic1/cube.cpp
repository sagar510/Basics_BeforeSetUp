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
		gl_Position=vec4(0.4*pos.x,0.4*pos.y,0.4*pos.z,1.0);		\n\
	}";

//Fragment Shader
static const char* fshader = "										\n\
	#version 330						     						 \n\
	out vec4 colour;												  \n\
	void main(){													   \n\
		colour = vec4(1.0f,0.0f,0.0f,1.0f);							    \n\
	}															         \n\
";

void createTriangle() {

	GLfloat vertices[] = {
		-1.0f,-1.0f,1.0f,
		-1.0f,1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		1.0f,1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		-1.0f,1.0f,1.0f,

		- 1.0f,-1.0f,-1.0f,
		-1.0f,1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f,1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,1.0f,-1.0f,

		1.0f,1.0f,1.0f,
		1.0f,1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		1.0f,1.0f,-1.0f,

		-1.0f,1.0f,1.0f,
		-1.0f,1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,1.0f,
		-1.0f,-1.0f,1.0f,
		-1.0f,1.0f,-1.0f,

		-1.0f,1.0f,1.0f,
		-1.0f,1.0f,-1.0f,
		1.0f,1.0f,-1.0f,
		-1.0f,1.0f,1.0f,
		1.0f,1.0f,1.0f,
		1.0f,1.0f,-1.0f,

		-1.0f,-1.0f,1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		1.0f,-1.0f,-1.0f

	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//VertexAttributePointer(0,3,GL_FLOAT,);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,0);

	//These all are that, we are unbinding here
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

	return;
}


//Create Shader Program
void compileShaders() {

	shader = glCreateProgram();

	if (!shader) {
		printf("Error, Creating Shader Program");
		return;
	}

	AddShader(shader, vshader, GL_VERTEX_SHADER);
	AddShader(shader, fshader, GL_FRAGMENT_SHADER);

	GLint result;
	GLchar elog[1024] = { 0 };

	glLinkProgram(shader);
	glGetShaderiv(shader, GL_LINK_STATUS, &result);

	if (!result) {
		glGetProgramInfoLog(shader, sizeof(elog), NULL, elog);
		printf("Error linking program %s", elog);
		return;
	}


	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);

	if (!result) {
		glGetProgramInfoLog(shader, sizeof(elog), NULL, elog);
		printf("Error while validating shader program %s", elog);
		return;
	}

}


int main() {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Filled_Cube", NULL, NULL);

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	glewInit();

	glViewport(0, 0, 800, 800);

	createTriangle();
	compileShaders();

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		glUseProgram(shader);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6*6);

		glBindVertexArray(0);
		glUseProgram(0);

		glfwSwapBuffers(window);
	}

	return 0;
}*/