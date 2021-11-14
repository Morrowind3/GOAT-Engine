#include "Goat.hpp"

Goat::Goat(Transform transform) : GameObject(transform, Sprite{"Goat.png", true}, true) {
    _goatTestScript = std::make_unique<GoatTestScript>(*this,true);
    scripts.push_back(_goatTestScript.get());
}
