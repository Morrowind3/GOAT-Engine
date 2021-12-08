#ifndef GOAT_ENGINE_SAVEFILE_HPP
#define GOAT_ENGINE_SAVEFILE_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class SaveFile: public GameObject {
    public: SaveFile(int saveNumber, int currentHeight, int mountEverestHeight, int score, Transform transform, bool active);
};


#endif //GOAT_ENGINE_SAVEFILE_HPP
