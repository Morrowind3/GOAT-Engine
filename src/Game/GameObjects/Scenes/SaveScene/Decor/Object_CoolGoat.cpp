#include "Object_CoolGoat.hpp"
#include "../../../../Keys.hpp"
#include "Sprite_CoolGoat1.hpp"
#include "Sprite_CoolGoat2.hpp"
#include "Animator_CoolGoat.hpp"

Object_CoolGoat::Object_CoolGoat(Transform transform, bool active) : GameObject(transform, active) {
    auto& idle1 = sprites.insert(std::make_pair(Keys::IDLE, Sprite_CoolGoat1{true})).first->second;
    auto& idle2 = sprites.insert(std::make_pair(Keys::IDLE2, Sprite_CoolGoat2{false})).first->second;
    animators.insert(std::make_pair(Keys::ANIMATOR, Animator_CoolGoat{idle1, idle2, true}));
}
