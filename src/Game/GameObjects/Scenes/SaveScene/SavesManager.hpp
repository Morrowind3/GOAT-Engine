#ifndef GOAT_ENGINE_SAVESMANAGER_HPP
#define GOAT_ENGINE_SAVESMANAGER_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/API/Scene.hpp"

using namespace Engine;

class SavesManager: public GameObject {
    public: SavesManager(Scene& scene, bool active);
};


#endif //GOAT_ENGINE_SAVESMANAGER_HPP
