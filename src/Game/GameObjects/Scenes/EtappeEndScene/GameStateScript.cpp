#include "GameStateScript.hpp"
#include "../../../Keys.hpp"

GameStateScript::GameStateScript(std::shared_ptr<Timer> timer, bool active) : Script(active), _timer(std::move(timer)) {
}

void GameStateScript::onUpdate(double deltaTime) {
    auto gameState = _globals.gameGet(Keys::GAMESTATE);

    if(gameState == Keys::GAMESTATE_VICTORY){
        gameWon();
    }
    if(gameState == Keys::GAMESTATE_DEFEAT){
        gameLost();
    }
}

void GameStateScript::gameLost() {
    Globals::getInstance().gameRemove(Keys::TRASH_MAX);
    _engineCalls.changeScene(Keys::DEFEAT_SCREEN);
}

void GameStateScript::gameWon() {
    //TODO: This would be the place to check and update the high score.
     _timer->behaviors.at(Keys::TIMER)->scripts.at(Keys::TIMER)->onExternalEvent(); //Signal level end, write away time to scene
//    int milliseconds = std::stoi(Globals::getInstance().sceneGet(Keys::TIMER));
    Globals::getInstance().gameRemove(Keys::TRASH_MAX);
    _engineCalls.changeScene(Keys::VICTORY_SCREEN);
}
