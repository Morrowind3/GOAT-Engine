#include "Script_Cloud.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"

Script_Cloud::Script_Cloud(Object_Cloud& cloud, bool active) : Script(active), _cloud(cloud) {
}

void Script_Cloud::onUpdate(double deltaTime) {
    _cloud.transform.position.x += _wind;
    _timeSinceLastTurn += deltaTime;
    if (_timeSinceLastTurn > DURATION_BEFORE_OTHER_DIRECTION_IN_MS) {
        _timeSinceLastTurn = 0;
        _wind *= -1;
    }
}
