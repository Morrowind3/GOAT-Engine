#include "GameStateManager.hpp"
#include "../../Keys.hpp"
#include "GameStateBehavior.hpp"

GameStateManager::GameStateManager(SceneManager& sceneManager, bool active): GameObject(Transform{{0,0}}, active){
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<GameStateBehavior>(sceneManager, true)));
};