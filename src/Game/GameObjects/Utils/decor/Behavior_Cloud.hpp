#ifndef GOAT_ENGINE_BEHAVIOR_CLOUD_HPP
#define GOAT_ENGINE_BEHAVIOR_CLOUD_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Object_Cloud.hpp"

using namespace Engine;

class Behavior_Cloud : public Behavior {
public: Behavior_Cloud(Object_Cloud& cloud, bool active);

};


#endif //GOAT_ENGINE_BEHAVIOR_CLOUD_HPP
