#ifndef GOAT_ENGINE_RETRYBUTTON_HPP
#define GOAT_ENGINE_RETRYBUTTON_HPP

#include "../../../../Engine/SceneManager.hpp"

using namespace Engine;

class RetryButton : public GameObject {
    public: RetryButton(SceneManager& sceneManager, Transform transform, bool active);
};


#endif //GOAT_ENGINE_RETRYBUTTON_HPP
