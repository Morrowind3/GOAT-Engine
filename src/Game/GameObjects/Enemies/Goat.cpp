#include "Goat.hpp"

Goat::Goat(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(GOAT::IDLE1, Sprite{"Sprites/enemies/goat/goat_idle_1.png", true}));
    sprites.insert(std::make_pair(GOAT::IDLE2, Sprite{"Sprites/enemies/goat/goat_idle_2.png", false}));
    sprites.insert(std::make_pair(GOAT::ATTACK_STANCE, Sprite{"Sprites/enemies/goat/goat_attack_stance.png", false}));
    sprites.insert(std::make_pair(GOAT::ATTACK1, Sprite{"Sprites/enemies/goat/goat_attack_1.png", false}));
    sprites.insert(std::make_pair(GOAT::ATTACK2, Sprite{"Sprites/enemies/goat/goat_attack_2.png", false}));
    audioSources.insert(std::make_pair(GOAT::BLEATHING, AudioSource{"Sounds/Bleathing.ogg",AudioSourceType::SAMPLE,true,true}));
}
