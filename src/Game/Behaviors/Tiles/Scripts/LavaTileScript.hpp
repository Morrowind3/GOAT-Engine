#ifndef GOAT_ENGINE_LAVATILESCRIPT_HPP
#define GOAT_ENGINE_LAVATILESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"

using namespace Engine;

class LavaTileScript : public Script {
public:
    LavaTileScript(bool active);
    void onTriggerEnter2D(GameObject& object) override;
};

#endif //GOAT_ENGINE_LAVATILESCRIPT_HPP
