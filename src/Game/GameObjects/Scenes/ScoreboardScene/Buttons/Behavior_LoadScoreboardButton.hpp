#ifndef GOAT_ENGINE_BEHAVIOR_LOADSCOREBOARDBUTTON_HPP
#define GOAT_ENGINE_BEHAVIOR_LOADSCOREBOARDBUTTON_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Behavior_LoadScoreboardButton: public Behavior {
    public:
        /// Constructor for loading the scoreboard for one specific etappe
        Behavior_LoadScoreboardButton(unsigned short etappeNumber, Text& scoreboardHeader, AudioSource& clickSound, bool active);
        /// Constructor for loading the scoreboard for all etappes
        Behavior_LoadScoreboardButton(Text& scoreboardHeader, AudioSource& clickSound, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_LOADSCOREBOARDBUTTON_HPP
