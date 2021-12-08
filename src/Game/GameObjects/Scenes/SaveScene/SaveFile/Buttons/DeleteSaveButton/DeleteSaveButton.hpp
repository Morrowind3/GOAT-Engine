#ifndef GOAT_ENGINE_DELETESAVEBUTTON_HPP
#define GOAT_ENGINE_DELETESAVEBUTTON_HPP

#include "../../../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class DeleteSaveButton: public GameObject {
    public: DeleteSaveButton(int saveNumber, const Transform& transform, bool active);
};


#endif //GOAT_ENGINE_DELETESAVEBUTTON_HPP
