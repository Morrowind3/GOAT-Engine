//
// Created by Morrowind3 on 01/12/2021.
//

#include "TimerScript.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include <iostream>


void TimerScript::onUpdate(double deltaTime) {
    _totalMs += _clock.lastRecordedUnmodifiedDeltaTime();
    if((int) _totalMs * _engineCalls.speed() / 1000 >= 1){
        addSecond();    //minimize UI updates
        _totalMs = 0;
    };
}

void TimerScript::addSecond() {
    ++_totalSeconds;

    std::string timeString;
    timeString.reserve(5);
    int minutes = _totalSeconds / 60;
    int seconds = _totalSeconds % 60;

    if(minutes < 10){
        timeString.insert(0, "0" + std::to_string(minutes));
    } else {
        timeString.insert(0, std::to_string(minutes));
    }
    timeString.insert(2, ":");

    if(seconds < 10){
        timeString.insert(3, "0" + std::to_string(seconds));
    } else {
        timeString.insert(3, std::to_string(seconds));
    }

    _text.text = timeString;
}

void TimerScript::onExternalEvent() {
    Globals::getInstance().sceneStore(Keys::TIMER, std::to_string(_totalMs));
    Globals::getInstance().sceneStore(Keys::TEXT, _text.text);
}
