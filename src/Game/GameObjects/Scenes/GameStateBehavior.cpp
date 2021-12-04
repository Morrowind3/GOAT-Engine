#include "GameStateBehavior.hpp"
#include "../../Keys.hpp"
#include "EtappeEndScene/GameStateScript.hpp"

GameStateBehavior::GameStateBehavior(SceneManager& sceneManager, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::GAMESTATE,std::make_shared<GameStateScript>(sceneManager, true)));
}
