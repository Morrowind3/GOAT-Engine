//
// Created by Morrowind3 on 18/12/2021.
//

#ifndef GOAT_ENGINE_OBJECT_KEYHELPDESCRIPTION_HPP
#define GOAT_ENGINE_OBJECT_KEYHELPDESCRIPTION_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_KeyHelpDescription : public GameObject {
public:
    Object_KeyHelpDescription(std::string description, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_KEYHELPDESCRIPTION_HPP
