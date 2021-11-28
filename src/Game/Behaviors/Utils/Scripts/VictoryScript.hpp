#ifndef GOAT_ENGINE_VICTORYSCRIPT_HPP
#define GOAT_ENGINE_VICTORYSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"

using namespace Engine;

class VictoryScript : public Script {
public:
    VictoryScript(bool active);
    void OnStart() override;

private:
};


#endif //GOAT_ENGINE_VICTORYSCRIPT_HPP
