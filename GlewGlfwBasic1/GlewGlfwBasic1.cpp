/*#include<stdio.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

const GLint width = 800, height = 600;

int main1() {

	if (!glfwInit()) {
		printf("Graphic Library failed to initialize");
		glfwTerminate();
		return 1;
	}

	// Setting Up Graphic Library window properties
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

	// Sets No backward comptablity
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	// Now, we want forward compablity, So, we make forward compablity true
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);


	// Creating window type pointer, and initializing object of create window
	GLFWwindow* mainWindow = glfwCreateWindow(width,height,"LetsLearn1",NULL,NULL);

	if (mainWindow == NULL) {
		printf("Window Creation Failed");
		glfwTerminate();
		return 1;
	}

	// Buffer Information, it use to be in the middle
	int bufferwidth, bufferheight;
	glfwGetFramebufferSize(mainWindow,&bufferwidth,&bufferheight);

	// Say Terminal to use window
	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("GLEW Initialization Failed");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
	}

	// Set View Port yeah internal mei mere khyal se buffer hota hai, out of window
	glViewport(0,0,800,600);

	// Loop Until window gets closed
	while (!glfwWindowShouldClose(mainWindow)) {
		glfwPollEvents();

		glClearColor(0.0f,1.0f,1.0f,1);    // Front Buffer
		glClear(GL_COLOR_BUFFER_BIT);  //Y

		glfwSwapBuffers(mainWindow);
	}

	return 0;
}
*/