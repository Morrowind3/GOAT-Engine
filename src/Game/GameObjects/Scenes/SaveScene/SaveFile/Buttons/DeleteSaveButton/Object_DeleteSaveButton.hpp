#ifndef GOAT_ENGINE_OBJECT_DELETESAVEBUTTON_HPP
#define GOAT_ENGINE_OBJECT_DELETESAVEBUTTON_HPP

#include "../../../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_DeleteSaveButton: public GameObject {
    public: Object_DeleteSaveButton(int saveNumber, Script& loadSavesScript, const Transform& transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_DELETESAVEBUTTON_HPP
