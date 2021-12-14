#include "Script_Cloud.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"
#include <random>
#include <chrono>

Script_Cloud::Script_Cloud(Object_Cloud& cloud, bool active) : Script(active), _cloud(cloud) {
    if(Globals::getInstance().sceneExists(Keys::CLOUDS)){
        _wind = std::stod(Globals::getInstance().sceneGet(Keys::CLOUDS));
    } else {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::uniform_real_distribution<double> dist(-0.5, 0.5);
        std::default_random_engine random(seed);
        _wind = dist(random);
        Globals::getInstance().sceneStore(Keys::CLOUDS, std::to_string(_wind));
    }
}

void Script_Cloud::onUpdate(double deltaTime) {
    if(deltaTime == 0) return;

    _cloud.transform.position.x = _cloud.transform.position.x + _wind;
}