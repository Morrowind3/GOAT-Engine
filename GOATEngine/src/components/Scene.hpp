#ifndef GOATENGINE_SCENE_HPP
#define GOATENGINE_SCENE_HPP

#include "GameObject.hpp"

// TODO: Obviously needs fixing
namespace Engine {
    class Scene {
        public:
            explicit Scene(GameObject gameObject);
        private:
            GameObject _gameObject;
    };
}

#endif //GOATENGINE_SCENE_HPP
