#ifndef GOAT_ENGINE_OBJECT_SAVESMANAGER_HPP
#define GOAT_ENGINE_OBJECT_SAVESMANAGER_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/API/Scene.hpp"

using namespace Engine;

class Object_SavesManager: public GameObject {
    public: Object_SavesManager(Scene& scene, bool active);
};


#endif //GOAT_ENGINE_OBJECT_SAVESMANAGER_HPP
