#include "Object_TimerLine.hpp"
#include "../../../Keys.hpp"
#include "Behavior_TimeLine.hpp"

Object_TimerLine::Object_TimerLine(double pixelsPerMs, Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<Behavior_TimeLine>(*this, pixelsPerMs, true)));
    sprites.insert(std::make_pair(Keys::TIMER, Sprite{"Sprites/utils/Object_TimerLine.png",true}));
}
