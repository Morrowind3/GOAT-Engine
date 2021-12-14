#ifndef GOAT_ENGINE_SCRIPT_LAVATILE_HPP
#define GOAT_ENGINE_SCRIPT_LAVATILE_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"

using namespace Engine;

class Script_LavaTile : public Script {
public:
    Script_LavaTile(bool active);
    void onTriggerEnter2D(GameObject& object) override;
};

#endif //GOAT_ENGINE_SCRIPT_LAVATILE_HPP
