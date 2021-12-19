#ifndef GOAT_ENGINE_OBJECT_GOAT_HPP
#define GOAT_ENGINE_OBJECT_GOAT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../Player/Object_Player.hpp"

using namespace Engine;

class Object_Goat : public GameObject {
    public: Object_Goat(Object_Player& player, Transform transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_GOAT_HPP
