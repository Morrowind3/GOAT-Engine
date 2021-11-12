#ifndef GOATENGINE_GAMEOBJECT_HPP
#define GOATENGINE_GAMEOBJECT_HPP

// TODO: TEMPORARY VERSION OF GAME OBJECT!
#include "render/Sprite.hpp"

namespace Engine {
    class GameObject {
        public:
            explicit GameObject(Sprite sprite);
        private:
            Sprite _sprite;
    };
}

#endif //GOATENGINE_GAMEOBJECT_HPP
