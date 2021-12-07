#ifndef GOAT_ENGINE_GOATSENSOR_HPP
#define GOAT_ENGINE_GOATSENSOR_HPP


#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../Goat.hpp"

using namespace Engine;

class GoatSensor : public GameObject {
public: GoatSensor(GameObject& goat, Transform transform, bool active);
};


#endif //GOAT_ENGINE_GOATSENSOR_HPP
