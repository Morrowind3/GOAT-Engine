#ifndef GOATENGINE_SCENE_HPP
#define GOATENGINE_SCENE_HPP

// TODO: Obviously needs fixing
#include "../core/GameObject.hpp"

namespace Engine {
    class Scene {
        public:
            explicit Scene(GameObject gameObject);
        private:
            GameObject _gameObject;
    };
}

#endif //GOATENGINE_SCENE_HPP
