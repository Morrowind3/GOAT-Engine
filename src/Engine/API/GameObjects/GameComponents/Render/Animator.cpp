#include "Animator.hpp"

using namespace Engine;

Animator::Animator(uint16_t fps, bool loop, bool active):
        GameComponent(active), fps{fps}, loop{loop} {
}
