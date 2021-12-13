#ifndef GOAT_ENGINE_OBJECT_TIMERLINE_HPP
#define GOAT_ENGINE_OBJECT_TIMERLINE_HPP

#include "../../../../Engine/API/GameObjects/Transform.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_TimerLine : public GameObject {
    public: Object_TimerLine(double speed, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_TIMERLINE_HPP
