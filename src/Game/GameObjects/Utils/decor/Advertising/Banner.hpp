//
// Created by Morrowind3 on 10/12/2021.
//

#ifndef GOAT_ENGINE_BANNER_HPP
#define GOAT_ENGINE_BANNER_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Banner : public GameObject {
public:
    Banner(Transform tranform, bool active);
};


#endif //GOAT_ENGINE_BANNER_HPP
