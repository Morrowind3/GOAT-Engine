//
// Created by Morrowind3 on 08/12/2021.
//

#include "CloudScript.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include <random>
#include <chrono>

CloudScript::CloudScript(Cloud& cloud, bool active) : Script(active), _cloud(cloud) {
    if(Globals::getInstance().sceneExists(Keys::CLOUDS)){
        _wind = std::stod(Globals::getInstance().sceneGet(Keys::CLOUDS));
    } else {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::uniform_real_distribution<double> dist(-1, 1);
        std::default_random_engine random(seed);
        _wind = dist(random);
        Globals::getInstance().sceneStore(Keys::CLOUDS, std::to_string(_wind));
    }
}

void CloudScript::onUpdate(double deltaTime) {
    _cloud.transform.position.x = _cloud.transform.position.x + _wind;
}
