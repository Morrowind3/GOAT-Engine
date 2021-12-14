#ifndef GOAT_ENGINE_BEHAVIOR_TRASH_HPP
#define GOAT_ENGINE_BEHAVIOR_TRASH_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Object_Trash.hpp"

using namespace Engine;

class Behavior_Trash : public Behavior {
    public: Behavior_Trash(Object_Trash& trash, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_TRASH_HPP
