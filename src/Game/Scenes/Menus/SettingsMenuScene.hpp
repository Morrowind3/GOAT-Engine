#ifndef GOAT_ENGINE_SETTINGSMENUSCENE_HPP
#define GOAT_ENGINE_SETTINGSMENUSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_StaticScreen.hpp"

using namespace Engine;

class SettingsMenuScene : public SceneTemplate_StaticScreen {
    public: explicit SettingsMenuScene(SceneManager& manager);
};

#endif //GOAT_ENGINE_SETTINGSMENUSCENE_HPP
