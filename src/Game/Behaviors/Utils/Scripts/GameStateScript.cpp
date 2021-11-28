//
// Created by Morrowind3 on 27/11/2021.
//

#include "GameStateScript.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include <iostream>

void GameStateScript::onUpdate(double deltaTime) {
    auto gameState = Globals::getInstance().gameGet(Keys::GAMESTATE);

    if(gameState == Keys::GAMESTATE_VICTORY){
        gameWon();
    }
    if(gameState == Keys::GAMESTATE_DEFEAT){
        gameLost();
    }
}

void GameStateScript::gameLost() {
    _sceneManager.changeCurrentScene(Keys::DEFEAT_SCREEN);
}

void GameStateScript::gameWon() {
    _sceneManager.changeCurrentScene(Keys::VICTORY_SCREEN);
}
