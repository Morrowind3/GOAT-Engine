#include "Object_GameStateManager.hpp"
#include "../../Keys.hpp"
#include "Behavior_GameState.hpp"

Object_GameStateManager::Object_GameStateManager(const std::shared_ptr<Object_Timer>& timer, bool active): GameObject(Transform{{0,0}}, active){
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<Behavior_GameState>(timer, true)));
};
