#ifndef GOAT_ENGINE_BEHAVIOR_LOADSCOREBOARD_HPP
#define GOAT_ENGINE_BEHAVIOR_LOADSCOREBOARD_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Behavior_LoadScoreboard: public Behavior {
    public:
        /// Constructor for loading the scoreboard for one specific etappe
        Behavior_LoadScoreboard(unsigned short etappeNumber, Text& scoreboardHeader, bool active);
        /// Constructor for loading the scoreboard for all etappes
        Behavior_LoadScoreboard(Text& scoreboardHeader, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_LOADSCOREBOARD_HPP
