#ifndef GOAT_ENGINE_TRASHCOUNTERBEHAVIOR_HPP
#define GOAT_ENGINE_TRASHCOUNTERBEHAVIOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class TrashCounterBehavior : public Behavior {
public: TrashCounterBehavior(Text& trashText, bool active);
};


#endif //GOAT_ENGINE_TRASHCOUNTERBEHAVIOR_HPP
