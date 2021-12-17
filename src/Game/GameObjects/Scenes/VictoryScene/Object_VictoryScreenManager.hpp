#ifndef GOAT_ENGINE_OBJECT_VICTORYSCREENMANAGER_HPP
#define GOAT_ENGINE_OBJECT_VICTORYSCREENMANAGER_HPP

#include "../../../../Engine/API/GameObjects/Transform.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_VictoryScreenManager : public GameObject {
    public: Object_VictoryScreenManager(Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_VICTORYSCREENMANAGER_HPP
