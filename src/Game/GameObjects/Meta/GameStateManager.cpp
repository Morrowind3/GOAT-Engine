//
// Created by Morrowind3 on 27/11/2021.
//

#include "GameStateManager.hpp"
#include "../../Keys.hpp"
#include "../../Behaviors/Utils/GameStateBehavior.hpp"

GameStateManager::GameStateManager(SceneManager& sceneManager, bool active): GameObject(Transform{{0,0}}, active){
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<GameStateBehavior>(sceneManager, true)));

};