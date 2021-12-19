#ifndef GOAT_ENGINE_BEHAVIOR_SAVESMANAGER_HPP
#define GOAT_ENGINE_BEHAVIOR_SAVESMANAGER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/Scene.hpp"

using namespace Engine;

class Behavior_SavesManager: public Behavior {
    public: explicit Behavior_SavesManager(bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_SAVESMANAGER_HPP
