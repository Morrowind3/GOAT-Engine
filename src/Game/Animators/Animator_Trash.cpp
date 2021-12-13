#include "Animator_Trash.hpp"

Animator_Trash::Animator_Trash(Sprite& trash0, Sprite& trash1, Sprite& trash2, Sprite& trash3, bool active):
Animator(2, true, active) {
    sprites.emplace_back(&trash0);
    sprites.emplace_back(&trash1);
    sprites.emplace_back(&trash2);
    sprites.emplace_back(&trash3);
}
