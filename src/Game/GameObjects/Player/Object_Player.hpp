#ifndef GOAT_ENGINE_OBJECT_PLAYER_HPP
#define GOAT_ENGINE_OBJECT_PLAYER_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_Player : public GameObject {
    public: Object_Player(Transform transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_PLAYER_HPP
