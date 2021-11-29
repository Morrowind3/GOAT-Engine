#ifndef GOAT_ENGINE_CHEATSBEHAVIOR_HPP
#define GOAT_ENGINE_CHEATSBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class CheatsBehavior : public Behavior {
    public: CheatsBehavior(std::map<std::string,Text>& textObjects, AudioSource& pauseSound, AudioSource& speedUpSound,
                           AudioSource& slowDownSound, AudioSource& resetSpeedSound, AudioSource& errorSound, bool active);
};

#endif //GOAT_ENGINE_CHEATSBEHAVIOR_HPP
