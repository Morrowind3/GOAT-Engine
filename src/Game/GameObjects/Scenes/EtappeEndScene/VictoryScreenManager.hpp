#ifndef GOAT_ENGINE_VICTORYSCREENMANAGER_HPP
#define GOAT_ENGINE_VICTORYSCREENMANAGER_HPP

#include "../../../../Engine/API/GameObjects/Transform.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class VictoryScreenManager : public GameObject {
public: VictoryScreenManager(Transform transform, bool active);
};


#endif //GOAT_ENGINE_VICTORYSCREENMANAGER_HPP
