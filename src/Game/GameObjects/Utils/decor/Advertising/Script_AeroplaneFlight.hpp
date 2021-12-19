#ifndef GOAT_ENGINE_SCRIPT_AEROPLANEFLIGHT_HPP
#define GOAT_ENGINE_SCRIPT_AEROPLANEFLIGHT_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_Aeroplane.hpp"
#include "../../../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class Script_AeroplaneFlight : public Script {
public:
    Script_AeroplaneFlight(Object_Aeroplane& plane, bool active) : Script(active), _plane(plane){};
    void onUpdate(double deltaTime) override;
private:
    Object_Aeroplane& _plane;
    double _distanceTravelled = 0;
    double _speed = -3 * EngineCalls::getInstance().speed();;
    bool flyingLeft = true;
};


#endif //GOAT_ENGINE_SCRIPT_AEROPLANEFLIGHT_HPP
