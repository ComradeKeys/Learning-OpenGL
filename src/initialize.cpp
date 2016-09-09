#include "initialize.h" //containing the definitions for this class
#include <iostream> //for error messages
#include "SDL.h" //initializing SDL2

using namespace std;

//creating the window and applying its properties
void InitializeWindow(SDL_Window * window, int windowWidth, int windowLength)
{
	//initializing SDL2 components
	SDL_Init(SDL_INIT_VIDEO);

	if (SDL_INIT_VIDEO == NULL)
	{
		cout << "Sorry, SDL could not be initialized. Try running the program again.";
	}

	//creating the window
	window = SDL_CreateWindow("OpenGL!", 100, 100, windowWidth, windowLength, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (window == NULL)
	{
		cout << "Sorry, the window could not be created. Try running the program again.";
	}
}
