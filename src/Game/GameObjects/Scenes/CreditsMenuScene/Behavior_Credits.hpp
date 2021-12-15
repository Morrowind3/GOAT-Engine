#ifndef GOAT_ENGINE_BEHAVIOR_CREDITS_HPP
#define GOAT_ENGINE_BEHAVIOR_CREDITS_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Behavior_Credits: public Behavior {
    public: Behavior_Credits(const std::vector<Text*>& creditsText, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_CREDITS_HPP
