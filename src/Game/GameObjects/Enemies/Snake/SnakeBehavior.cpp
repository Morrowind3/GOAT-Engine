#include "SnakeBehavior.hpp"
#include "../../../Keys.hpp"
#include "SnakeScript.hpp"

// Expected behavior:
// - does nothing, hiding ...
// - when player steps on it, emerge from ground, deal damage and push player back

SnakeBehavior::SnakeBehavior(Snake& snake, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SNAKE, std::make_shared<SnakeScript>(snake, true)));
}