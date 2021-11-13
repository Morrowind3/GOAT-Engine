//
// Created by Stijn van Loon on 12-11-2021.
//

#ifndef GOATENGINE_SCENEMANAGER_HPP
#define GOATENGINE_SCENEMANAGER_HPP

#include "../core/Scene.hpp"

#include <map>

namespace Engine {
    class SceneManager {
    private:
        Scene* activeScene = nullptr;
        std::map<size_t, Scene*> registry{};
        size_t idCounter{1};

    public:
        Scene* getActiveScene();

        // change current active scene, must first be loaded!
        void setActiveScene(size_t id);

        bool hasActiveScene();

        // adds scene to registry
        void addScene(Scene* scene);

        // loads all assets needed for the scene
        void loadScene(size_t id);

        // unloads all assets needed for the scene
        void unloadScene(size_t id);

        // destroys the scene, must first be unloaded!
        void destoryScene(size_t id);
    };
}


#endif //GOATENGINE_SCENEMANAGER_HPP
