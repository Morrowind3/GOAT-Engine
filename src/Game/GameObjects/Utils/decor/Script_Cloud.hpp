#ifndef GOAT_ENGINE_SCRIPT_CLOUD_HPP
#define GOAT_ENGINE_SCRIPT_CLOUD_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_Cloud.hpp"

using namespace Engine;

class Script_Cloud : public Script {
public:
    Script_Cloud(Object_Cloud& cloud, bool active);
    void onUpdate(double deltaTime) override;
private:
    double _wind;
    Object_Cloud& _cloud;
};


#endif //GOAT_ENGINE_SCRIPT_CLOUD_HPP
