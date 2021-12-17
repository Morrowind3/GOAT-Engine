#include "Script_GameState.hpp"
#include "../../../Keys.hpp"

Script_GameState::Script_GameState(std::shared_ptr<Object_Timer> timer, bool active) : Script(active), _timer(std::move(timer)) {
}

void Script_GameState::onUpdate(double deltaTime) {
    auto gameState = _globals.gameGet(Keys::GAMESTATE);

    if(gameState == Keys::GAMESTATE_VICTORY) {
        gameWon();
    }
    if(gameState == Keys::GAMESTATE_DEFEAT) {
        gameLost();
    }
}

void Script_GameState::gameLost() {
    _globals.gameRemove(Keys::TRASH_MAX);
    _engineCalls.changeScene(Keys::DEFEAT_SCREEN);
}

void Script_GameState::gameWon() {
    _globals.gameRemove(Keys::TRASH_MAX);
    _engineCalls.changeScene(Keys::VICTORY_SCREEN);
}
