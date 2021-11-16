#include "Goat.hpp"

Goat::Goat(Transform transform) : GameObject(transform, true) {
    _goatBehavior = std::make_unique<GoatBehavior>(*this,true);
    behaviors.push_back(*_goatBehavior);
    sprites.emplace_back("Goat.png", true);
}
