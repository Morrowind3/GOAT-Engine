#include "SnakeBehavior.hpp"
#include "../../Keys.hpp"
#include "Scripts/SnakeScript.hpp."

SnakeBehavior::SnakeBehavior(Snake& snake, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SNAKE, std::make_shared<SnakeScript>(snake, true)));
}