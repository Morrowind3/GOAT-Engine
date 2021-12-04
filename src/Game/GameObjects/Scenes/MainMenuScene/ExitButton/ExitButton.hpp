#ifndef GOAT_ENGINE_EXITBUTTON_HPP
#define GOAT_ENGINE_EXITBUTTON_HPP

#include "../../../../../Engine/SceneManager.hpp"

using namespace Engine;

class ExitButton : public GameObject {
    public: ExitButton(SceneManager& sceneManager, Transform transform, bool active);
};


#endif //GOAT_ENGINE_EXITBUTTON_HPP
