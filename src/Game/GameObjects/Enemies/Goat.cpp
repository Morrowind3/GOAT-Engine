#include "Goat.hpp"
#include "../../Keys.hpp"

Goat::Goat(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::IDLE, Sprite{"Sprites/enemies/goat/goat_idle_1.png", false}));
    sprites.insert(std::make_pair(Keys::IDLE2, Sprite{"Sprites/enemies/goat/goat_idle_2.png", false}));
    sprites.insert(std::make_pair(Keys::ATTACK_STANCE, Sprite{"Sprites/enemies/goat/goat_attack_stance.png", true}));
    sprites.insert(std::make_pair(Keys::ATTACK1, Sprite{"Sprites/enemies/goat/goat_attack_1.png", false}));
    sprites.insert(std::make_pair(Keys::ATTACK2, Sprite{"Sprites/enemies/goat/goat_attack_2.png", false}));
    audioSources.insert(std::make_pair(Keys::BLEATHING, AudioSource{"Sounds/Bleathing.ogg",AudioSourceType::SAMPLE,true,true}));
}
