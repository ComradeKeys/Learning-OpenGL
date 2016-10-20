#ifndef SCENE_H
#define SCENE_H

#include "Mesh.h"
#include "Input.h"
#include <vector>
using namespace std;

class Scene {
        public:
                Scene(int type);
                int Run(void);
                ~Scene();
        private:
                vector<Mesh> m_meshes;
                Input m_input;
};

#endif
