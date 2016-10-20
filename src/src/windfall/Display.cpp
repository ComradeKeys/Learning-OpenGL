#include "Display.h"

Display::Display(const string &title, const int width, const int height) {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
                throw runtime_error(SDL_GetError());

        gWin = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED, width, height,
                        SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
        gCont = SDL_GL_CreateContext(gWin);

        if (gWin == NULL)
                throw runtime_error(SDL_GetError());
        else if (!gCont)
                throw runtime_error(SDL_GetError());

        if (glewInit() != GLEW_OK)
                throw runtime_error("Cannot initialize GLEW");

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void Display::Clear(void) {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::Swap(void) {
        SDL_GL_SwapWindow(gWin);
}

Display::~Display() {
        SDL_GL_DeleteContext(gCont);
        SDL_DestroyWindow(gWin);
        SDL_Quit();
}
