#ifndef GOAT_ENGINE_BEHAVIOR_SCOREBOARDMANAGER_HPP
#define GOAT_ENGINE_BEHAVIOR_SCOREBOARDMANAGER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Behavior_ScoreboardManager: public Behavior {
    public: Behavior_ScoreboardManager(Text& scoreboardHeader, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_SCOREBOARDMANAGER_HPP
