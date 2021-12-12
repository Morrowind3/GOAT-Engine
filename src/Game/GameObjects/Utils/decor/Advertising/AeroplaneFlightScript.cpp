//
// Created by Morrowind3 on 11/12/2021.
//

#include "AeroplaneFlightScript.hpp"
#include "../../../../Keys.hpp"

void AeroplaneFlightScript::onUpdate(double deltaTime) {
    if(deltaTime == 0) return;
    if(!flyingLeft && _distanceTravelled >= _plane.maxDist || flyingLeft && _distanceTravelled <= (_plane.maxDist * -1)){
        flyingLeft = !flyingLeft;
        if(flyingLeft){
            _speed = -3 * EngineCalls::getInstance().speed();
        } else {
            _speed = 3 * EngineCalls::getInstance().speed();
        }

        _plane.transform.flip = flyingLeft ? FLIP::FLIP_NONE : FLIP::FLIP_HORIZONTAL;
        for(auto& attached : _plane.getAttachedObjects()){
            attached->transform.position.x = flyingLeft ? attached->transform.position.x + 545 : attached->transform.position.x - 545;
                if(attached->tags.find(Keys::NO_FLIP) == attached->tags.end()){
                    attached->transform.flip =  flyingLeft ? FLIP::FLIP_NONE : FLIP::FLIP_HORIZONTAL;
                }
        }
    }
    _distanceTravelled += _speed;
    _plane.transform.position.x =  _plane.transform.position.x + _speed;
    for(auto& attached : _plane.getAttachedObjects()){
        attached->transform.position.x = attached->transform.position.x + _speed;
    }
}
