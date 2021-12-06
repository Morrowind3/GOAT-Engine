#include "GameStateScript.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"

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
    Globals::getInstance().gameRemove(Keys::TRASH_MAX);
    _sceneManager.changeCurrentScene(Keys::DEFEAT_SCREEN);
}

void GameStateScript::gameWon() {
    //TODO: This would be the place to check and update the high score.
     _timer->behaviors.at(Keys::TIMER)->scripts.at(Keys::TIMER)->onExternalEvent(); //Signal level end, write away time to scene
//    int milliseconds = std::stoi(Globals::getInstance().sceneGet(Keys::TIMER));
    Globals::getInstance().gameRemove(Keys::TRASH_MAX);

    _sceneManager.changeCurrentScene(Keys::VICTORY_SCREEN);
}
