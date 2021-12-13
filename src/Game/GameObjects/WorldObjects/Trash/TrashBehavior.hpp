#ifndef GOAT_ENGINE_TRASHBEHAVIOR_HPP
#define GOAT_ENGINE_TRASHBEHAVIOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Trash.hpp"

using namespace Engine;

class TrashBehavior : public Behavior {
    public: TrashBehavior(Trash& trash, bool active);
};


#endif //GOAT_ENGINE_TRASHBEHAVIOR_HPP
