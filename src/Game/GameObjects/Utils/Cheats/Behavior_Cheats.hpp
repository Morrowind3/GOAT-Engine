#ifndef GOAT_ENGINE_BEHAVIOR_CHEATS_HPP
#define GOAT_ENGINE_BEHAVIOR_CHEATS_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"
#include "../../../../Engine/SceneManager.hpp"
#include "../../Player/Object_Player.hpp"

using namespace Engine;

class Behavior_Cheats : public Behavior {
    public: Behavior_Cheats(Scene& scene, Object_Player& player, std::map<std::string,Text>& textObjects,
                           AudioSource& speedUpSound, AudioSource& slowDownSound, AudioSource& resetSpeedSound,
                           AudioSource& errorSound, AudioSource& beatGameSound, AudioSource& healSound,
                           AudioSource& flipSound, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_CHEATS_HPP
