//
// Created by Morrowind3 on 06/12/2021.
//

#ifndef GOAT_ENGINE_TRASHCOUNTER_HPP
#define GOAT_ENGINE_TRASHCOUNTER_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class TrashCounter : public GameObject {
public: explicit TrashCounter(bool active);
};


#endif //GOAT_ENGINE_TRASHCOUNTER_HPP