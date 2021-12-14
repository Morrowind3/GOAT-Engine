#ifndef GOAT_ENGINE_BEHAVIOR_TRASHCOUNTER_HPP
#define GOAT_ENGINE_BEHAVIOR_TRASHCOUNTER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Behavior_TrashCounter : public Behavior {
public: Behavior_TrashCounter(Text& trashText, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_TRASHCOUNTER_HPP
