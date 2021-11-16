#include "Goat.hpp"

#include "../Behaviors/GoatBehavior.hpp"
#include "../Behaviors/AdditionalBehavior.hpp"

Goat::Goat(Transform transform) : GameObject(transform, true) {
    _goatBehavior = std::make_unique<GoatBehavior>(*this,true);
    behaviors.push_back(*_goatBehavior);
    _additionalBehavior = std::make_unique<AdditionalBehavior>(true);
    behaviors.push_back(*_additionalBehavior);
    sprites.emplace_back("Goat.png", true);
}
