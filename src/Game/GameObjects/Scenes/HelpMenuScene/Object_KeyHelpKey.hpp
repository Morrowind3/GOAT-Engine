//
// Created by Morrowind3 on 18/12/2021.
//

#ifndef GOAT_ENGINE_OBJECT_KEYHELPKEY_HPP
#define GOAT_ENGINE_OBJECT_KEYHELPKEY_HPP


#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_KeyHelpKey : public GameObject {
public:
    Object_KeyHelpKey(const std::string& key, Transform transform, bool active);
};



#endif //GOAT_ENGINE_OBJECT_KEYHELPKEY_HPP
