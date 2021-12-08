#ifndef GOAT_ENGINE_GAMESTATEMANAGER_HPP
#define GOAT_ENGINE_GAMESTATEMANAGER_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../Utils/Timer/Timer.hpp"

using namespace Engine;

class GameStateManager : public GameObject {
    public: GameStateManager(const std::shared_ptr<Timer>& timer, bool active);
};


#endif //GOAT_ENGINE_GAMESTATEMANAGER_HPP
