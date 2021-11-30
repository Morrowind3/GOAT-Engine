#ifndef GOAT_ENGINE_CHEATSBEHAVIOR_HPP
#define GOAT_ENGINE_CHEATSBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class CheatsBehavior : public Behavior {
    public: CheatsBehavior(SceneManager& sceneManager, Scene& scene, Player& player, std::map<std::string,Text>& textObjects,
                           AudioSource& speedUpSound, AudioSource& slowDownSound, AudioSource& resetSpeedSound,
                           AudioSource& errorSound, AudioSource& beatGameSound, bool active);
};

#endif //GOAT_ENGINE_CHEATSBEHAVIOR_HPP
