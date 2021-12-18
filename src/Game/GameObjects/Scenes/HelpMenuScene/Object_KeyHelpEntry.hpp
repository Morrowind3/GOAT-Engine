#ifndef GOAT_ENGINE_OBJECT_KEYHELPENTRY_HPP
#define GOAT_ENGINE_OBJECT_KEYHELPENTRY_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_KeyHelpEntry : public GameObject {
public:
    Object_KeyHelpEntry(std::string description, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_KEYHELPENTRY_HPP
