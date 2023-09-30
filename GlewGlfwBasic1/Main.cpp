/*#include<stdio.h>
#include<string.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include "Debug/"

int main() {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Triangle", NULL, NULL);

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
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glBindVertexArray(0);
		glUseProgram(0);

		glfwSwapBuffers(window);
	}

	return 0;
}*/