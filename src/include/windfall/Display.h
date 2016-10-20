#ifndef DISPLAY_H
#define DISPLAY_H

#include "SDL.h"
#include "GL/glew.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Display {
        public:
                Display(const string &filename, const int width, const int height);
                void Clear(void);
                void Swap(void);
                ~Display();
        private:
                SDL_Window *gWin;
                SDL_GLContext gCont;
};

#endif
