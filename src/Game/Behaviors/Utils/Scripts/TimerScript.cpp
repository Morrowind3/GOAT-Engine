//
// Created by Morrowind3 on 01/12/2021.
//

#include "TimerScript.hpp"
#include <iostream>


void TimerScript::onUpdate(double deltaTime) {
    totalMs += _clock.lastRecordedUnmodifiedDeltaTime();
    if((int) totalMs * _engineCalls.speed() / 1000 >= 1){
        addSecond();    //minimize UI updates
        totalMs = 0;
    };
}

void TimerScript::addSecond() {
    ++totalSeconds;

    std::string timeString;
    timeString.reserve(5);
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

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
