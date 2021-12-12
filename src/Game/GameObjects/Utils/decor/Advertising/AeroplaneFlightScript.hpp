#ifndef GOAT_ENGINE_AEROPLANEFLIGHTSCRIPT_HPP
#define GOAT_ENGINE_AEROPLANEFLIGHTSCRIPT_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Aeroplane.hpp"
#include "../../../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class AeroplaneFlightScript : public Script {
public:
    AeroplaneFlightScript(Aeroplane& plane, bool active) : Script(active), _plane(plane){};
    void onUpdate(double deltaTime) override;
private:
    Aeroplane& _plane;
    double _distanceTravelled = 0;
    double _speed = -3 * EngineCalls::getInstance().speed();;
    bool flyingLeft = true;
};


#endif //GOAT_ENGINE_AEROPLANEFLIGHTSCRIPT_HPP
