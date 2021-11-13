#ifndef GOATENGINE_GAMEOBJECT_HPP
#define GOATENGINE_GAMEOBJECT_HPP

// TODO: TEMPORARY VERSION OF GAME OBJECT!
#include "../components/render/Sprite.hpp"

namespace Engine {
    class GameObject {
        public:
            explicit GameObject(Sprite sprite);
            [[nodiscard]] Sprite getSprite() const;
        private:
            Sprite _sprite;
    };
}

#endif //GOATENGINE_GAMEOBJECT_HPP
