#include "ExampleGoat.hpp"

ExampleGoat::ExampleGoat(Transform transform) : GameObject(transform, true) {
    _goatBehavior = std::make_unique<TestGoatBehavior>(*this,true);
    behaviors.push_back(*_goatBehavior);
    sprites.emplace_back("Goat.png", true);
}
