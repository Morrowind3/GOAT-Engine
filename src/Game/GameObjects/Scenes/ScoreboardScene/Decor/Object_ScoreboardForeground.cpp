#include "Object_ScoreboardForeground.hpp"
#include "../../../../Keys.hpp"
#include "Sprite_ScoreboardForeground.hpp"

Object_ScoreboardForeground::Object_ScoreboardForeground(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::_, Sprite_ScoreboardForeground{true}));
}
