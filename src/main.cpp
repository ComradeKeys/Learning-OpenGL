#include <iostream> //for error messages
#include <array> //for storing vertices
#include "SDL.h" //handles window creation and drawing
#include "glew.h" //extension wrangler ; D
#include "initialize.h" //our setup file

using namespace std;


int main(int argc, char* argv[])
{
	//creating a window
	SDL_Window* window = NULL;

	//setting up the window after it has been defined
	InitializeWindow(window,720,480);

	//creating the OpenGL context
	SDL_GLContext context=SDL_GL_CreateContext(window);

	//creating the array that will hold the triangle vertices
	float vertices[]
	{
		.0,.5,.0,
		-.5,-.5,.0,
		.5,-.5,.0
	};

	//initializing glew
	glewInit();

	//this will keep the main loop going when we start drawing
	bool done = false;

	//main loop
	while(!done)
	{
		//clearing the screen before drawing each frame
		glClearColor(255, 255, 255, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		/*drawing a triangle using a VBO :O */
		//generating a buffer name
		GLuint bufferID;
		glGenBuffers(1, &bufferID); /*THIS IS THE PROBLEM!!!*/

		//binding the buffer
		glBindBuffer(GL_ARRAY_BUFFER,bufferID);
		
		//filling the buffer
		glBufferData(GL_ARRAY_BUFFER,sizeof(GL_FLOAT)*9,vertices,GL_STATIC_DRAW);

		//rendering triangles with arrays
		glEnableClientState(GL_ARRAY_BUFFER);
		glDrawArrays(GL_TRIANGLES,0,3);
		glDisableClientState(GL_ARRAY_BUFFER);

		//cleaning up
		glDeleteBuffers(1, &bufferID);

		//rendering and waiting for the next frame
		SDL_GL_SwapWindow(window);
		SDL_Delay(500);
	}

	//cleaning up
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}