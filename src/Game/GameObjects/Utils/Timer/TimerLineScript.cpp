#include "TimerLineScript.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"
#include <iostream>

//TODO: When we have high scores, base the line on the top score's time.
void TimerLineScript::onUpdate(double deltaTime) {
    _timerLine.transform.position.x = _timerLine.transform.position.x +  _speed * EngineCalls::getInstance().speed();
}
