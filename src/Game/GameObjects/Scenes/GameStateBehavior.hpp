#ifndef GOAT_ENGINE_GAMESTATEBEHAVIOR_HPP
#define GOAT_ENGINE_GAMESTATEBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../Utils/Timer/Timer.hpp"
#include "../../GameSceneManager.hpp"

using namespace Engine;

class GameStateBehavior: public Behavior {
    public:  GameStateBehavior(SceneManager& sceneManager, std::shared_ptr<Timer> timer, bool active);
};

#endif //GOAT_ENGINE_GAMESTATEBEHAVIOR_HPP
