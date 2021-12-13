#include "Behavior_Snake.hpp"
#include "../../../Keys.hpp"
#include "Script_Snake.hpp"

// Expected behavior:
// - does nothing, hiding ...
// - when player steps on it, emerge from ground, deal damage and push player back

Behavior_Snake::Behavior_Snake(Object_Snake& snake, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SNAKE, std::make_shared<Script_Snake>(snake, true)));
}