#include "TimerLine.hpp"
#include "../../../Keys.hpp"
#include "TimerLineBehavior.hpp"

TimerLine::TimerLine(double pixelsPerMs, Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<TimerLineBehavior>(*this, pixelsPerMs, true)));
    sprites.insert(std::make_pair(Keys::TIMER, Sprite{"Sprites/utils/TimerLine.png",true}));
}
