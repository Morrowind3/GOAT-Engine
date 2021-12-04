#ifndef GOAT_ENGINE_GAMESTATEBEHAVIOR_HPP
#define GOAT_ENGINE_GAMESTATEBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class GameStateBehavior: public Behavior {
    public: explicit GameStateBehavior(SceneManager& sceneManager, bool active);
};

#endif //GOAT_ENGINE_GAMESTATEBEHAVIOR_HPP
