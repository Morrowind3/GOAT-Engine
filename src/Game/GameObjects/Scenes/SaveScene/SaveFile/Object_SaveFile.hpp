#ifndef GOAT_ENGINE_OBJECT_SAVEFILE_HPP
#define GOAT_ENGINE_OBJECT_SAVEFILE_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_SaveFile: public GameObject {
    public: Object_SaveFile(int saveNumber, int currentHeight, int mountEverestHeight, int score, const Transform& transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_SAVEFILE_HPP
