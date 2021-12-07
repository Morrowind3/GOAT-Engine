//
// Created by Morrowind3 on 05/12/2021.
//

#ifndef GOAT_ENGINE_TRASH_HPP
#define GOAT_ENGINE_TRASH_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Trash : public GameObject {
public: Trash(Transform transform, bool active);
};


#endif //GOAT_ENGINE_TRASH_HPP
