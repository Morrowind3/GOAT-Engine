#include "GameStateManager.hpp"
#include "../../../Keys.hpp"
#include "../../../Behaviors/Utils/GameStateBehavior.hpp"

GameStateManager::GameStateManager(SceneManager& sceneManager, const std::shared_ptr<Timer>& timer, bool active): GameObject(Transform{{0,0}}, active){
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<GameStateBehavior>(sceneManager, timer, true)));
};
