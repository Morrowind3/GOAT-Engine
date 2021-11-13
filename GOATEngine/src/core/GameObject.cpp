#include "GameObject.hpp"

using namespace Engine;

GameObject::GameObject(Sprite sprite): _sprite {std::move( sprite )} {

}

Sprite GameObject::getSprite() const {
    return _sprite;
}
