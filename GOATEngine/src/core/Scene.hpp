#ifndef GOATENGINE_SCENE_HPP
#define GOATENGINE_SCENE_HPP

#include "Base.hpp"
#include "GameObject.hpp"

#include <map>

namespace Engine {
    class Scene {
        private:
            size_t sceneId;
            std::map <size_t, GameObject> registry{};
            size_t idCounter{1};

        public:
            explicit Scene(size_t id) : sceneId(id) {};
            size_t getId();
            std::map<size_t,GameObject> getAllGameObjects();
            GameObject getGameObject(size_t id);
            void addGameObject(GameObject gameObject);
    };
}

#endif //GOATENGINE_SCENE_HPP
