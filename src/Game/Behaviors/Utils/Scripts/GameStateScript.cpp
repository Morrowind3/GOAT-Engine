//
// Created by Morrowind3 on 27/11/2021.
//

#include "GameStateScript.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include <iostream>

void GameStateScript::OnUpdate(double deltaTime) {
    auto gameState = Globals::GetInstance().gameGet(Keys::GAMESTATE);

    if(gameState == Keys::GAMESTATE_VICTORY){
        GameWon();
    }
    if(gameState == Keys::GAMESTATE_DEFEAT){
        GameLost();
    }
}

void GameStateScript::GameLost() {
    _sceneManager.ChangeCurrentScene(Keys::DEFEAT_SCREEN);
}

void GameStateScript::GameWon() {
    _sceneManager.ChangeCurrentScene(Keys::VICTORY_SCREEN);
}
