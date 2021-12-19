#ifndef GOAT_ENGINE_BEHAVIOR_VICTORYSCREEN_HPP
#define GOAT_ENGINE_BEHAVIOR_VICTORYSCREEN_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Behavior_VictoryScreen : public Behavior {
    public: Behavior_VictoryScreen(Text& trashText, Text& timeText, Text& scoreText, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_VICTORYSCREEN_HPP
