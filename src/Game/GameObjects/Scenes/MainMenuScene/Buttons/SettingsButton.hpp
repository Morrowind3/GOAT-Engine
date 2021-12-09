#ifndef GOAT_ENGINE_SETTINGSBUTTON_HPP
#define GOAT_ENGINE_SETTINGSBUTTON_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class SettingsButton : public GameObject {
    public: SettingsButton(Transform transform, bool active);
};

#endif //GOAT_ENGINE_SETTINGSBUTTON_HPP
