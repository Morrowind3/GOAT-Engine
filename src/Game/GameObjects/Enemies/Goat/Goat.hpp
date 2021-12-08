#ifndef GOAT_ENGINE_GOAT_HPP
#define GOAT_ENGINE_GOAT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "GoatSensor/GoatSensor.hpp"

using namespace Engine;

class Goat : public GameObject {
public: Goat(Transform transform, bool active);
};

#endif //GOAT_ENGINE_GOAT_HPP
