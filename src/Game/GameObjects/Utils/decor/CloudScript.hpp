#ifndef GOAT_ENGINE_CLOUDSCRIPT_HPP
#define GOAT_ENGINE_CLOUDSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Cloud.hpp"

using namespace Engine;

class CloudScript : public Script {
public:
    CloudScript(Cloud& cloud, bool active);
    void onUpdate(double deltaTime) override;
private:
    double _wind;
    Cloud& _cloud;
};


#endif //GOAT_ENGINE_CLOUDSCRIPT_HPP
