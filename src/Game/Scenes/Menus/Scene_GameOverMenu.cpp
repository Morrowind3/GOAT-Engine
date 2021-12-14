#include "Scene_GameOverMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/Object_DefeatBackground.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/Object_SelectEtappeButton.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/Object_RetryButton.hpp"
#include "../../Layers.hpp"

Scene_GameOverMenu::Scene_GameOverMenu() : SceneTemplate_Menu(Keys::DEFEAT_SCREEN) {
    gameObjects.emplace_back(std::make_shared<Object_DefeatBackground>(Transform{Point{0, 0}, 0, 0,0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<Object_SelectEtappeButton>(
            Transform{Point{560, 830}, LAYER::UI, 0,0, 6, 5}, true));
    gameObjects.emplace_back(std::make_shared<Object_RetryButton>(
            Transform{Point{970, 830}, LAYER::UI, 0, 0, 6, 5}, true));
}
