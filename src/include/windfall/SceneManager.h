#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"
#include <stdexcept>
#include <stack>

class SceneManager {
        public:
                static SceneManager* instance() {
                        if (!s_instance)
                                s_instance = new SceneManager;
                        return s_instance;
                }
                void CreateScene(int type);
                int RunTop(void);
                ~SceneManager();
        private:
                SceneManager();
                static SceneManager *s_instance;
                stack<Scene> sceneStack;
};

#endif
