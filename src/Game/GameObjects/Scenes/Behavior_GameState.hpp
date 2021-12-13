#ifndef GOAT_ENGINE_BEHAVIOR_GAMESTATE_HPP
#define GOAT_ENGINE_BEHAVIOR_GAMESTATE_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../Utils/Timer/Object_Timer.hpp"
#include "../../GameSceneManager.hpp"

using namespace Engine;

class Behavior_GameState: public Behavior {
    public: Behavior_GameState(std::shared_ptr<Object_Timer> timer, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_GAMESTATE_HPP
