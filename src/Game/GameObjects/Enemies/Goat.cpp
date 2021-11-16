#include "Goat.hpp"

Goat::Goat(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(GOAT::IDLE1, Sprite{"Sprites/enemies/goat/goat_idle_1.png", true}));
    sprites.insert(std::make_pair(GOAT::IDLE2, Sprite{"Sprites/enemies/goat/goat_idle_2.png", true}));
    sprites.insert(std::make_pair(GOAT::ATTACK_STANCE, Sprite{"Sprites/enemies/goat/goat_attack_stance.png", true}));
    sprites.insert(std::make_pair(GOAT::ATTACK1, Sprite{"Sprites/enemies/goat/goat_attack_1.png", true}));
    sprites.insert(std::make_pair(GOAT::ATTACK2, Sprite{"Sprites/enemies/goat/goat_attack_2.png", true}));
    activeSprite = &sprites.at(GOAT::IDLE1);
}
