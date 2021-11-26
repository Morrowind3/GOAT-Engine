#ifndef GOAT_ENGINE_SETTINGSBUTTON_HPP
#define GOAT_ENGINE_SETTINGSBUTTON_HPP


#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class SettingsButton : public GameObject {
public:
    SettingsButton(SceneManager& sceneManager, Transform transform, bool active);
};



#endif //GOAT_ENGINE_SETTINGSBUTTON_HPP
