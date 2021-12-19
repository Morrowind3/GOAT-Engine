#include "Script_TimerLine.hpp"
#include "../../../Keys.hpp"

Script_TimerLine::Script_TimerLine(Object_TimerLine& timerLine, double speed, bool active) : Script(active), _speed(speed), _timerLine(timerLine){}

void Script_TimerLine::onStart() {
    storePosition();
}

/// Update position of line
void Script_TimerLine::onUpdate(double deltaTime) {
    if(_engineCalls.isPaused()) return;
    _timerLine.transform.position.x = _timerLine.transform.position.x + _speed * _engineCalls.speed();
    storePosition();
}

void Script_TimerLine::storePosition() {
    _globals.gameStore(Keys::LINE_LOCATION, std::to_string((int)_timerLine.transform.position.x));
}


