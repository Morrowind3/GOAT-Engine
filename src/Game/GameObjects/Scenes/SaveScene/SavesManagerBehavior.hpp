#ifndef GOAT_ENGINE_SAVESMANAGERBEHAVIOR_HPP
#define GOAT_ENGINE_SAVESMANAGERBEHAVIOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/Scene.hpp"

using namespace Engine;

class SavesManagerBehavior: public Behavior {
    public: SavesManagerBehavior(Scene& scene, bool active);
};


#endif //GOAT_ENGINE_SAVESMANAGERBEHAVIOR_HPP
