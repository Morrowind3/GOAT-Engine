#ifndef GOAT_ENGINE_OBJECT_HAWK_HPP
#define GOAT_ENGINE_OBJECT_HAWK_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../Player/Object_Player.hpp"

using namespace Engine;

class Object_Hawk : public GameObject {
    public: Object_Hawk(Object_Player &player, Transform transform, bool active);
    public: Object_Hawk(Transform transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_HAWK_HPP
