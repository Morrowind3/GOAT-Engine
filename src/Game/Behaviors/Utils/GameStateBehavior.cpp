//
// Created by Morrowind3 on 27/11/2021.
//

#include "GameStateBehavior.hpp"
#include "../../Keys.hpp"
#include "Scripts/GameStateScript.hpp"

GameStateBehavior::GameStateBehavior(SceneManager& sceneManager, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::GAMESTATE,std::make_shared<GameStateScript>(sceneManager, true)));
}
