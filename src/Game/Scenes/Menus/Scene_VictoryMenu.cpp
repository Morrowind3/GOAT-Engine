#include "Scene_VictoryMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/Object_VictoryScreenManager.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/Object_SelectEtappeButton.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/Object_NextEtappeButton.hpp"
#include "../../Layers.hpp"

Scene_VictoryMenu::Scene_VictoryMenu() : SceneTemplate_Menu(Keys::VICTORY_SCREEN) {
    gameObjects.emplace_back(std::make_shared<Object_VictoryScreenManager>( Transform{Point{0, 0}, 0,1, 0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<Object_SelectEtappeButton>(
            Transform{Point{560, 850}, LAYER::UI,0, 0, 6, 5}, true));
    gameObjects.emplace_back(std::make_shared<Object_NextEtappeButton>(
            Transform{Point{970, 850}, LAYER::UI, 0,0, 6, 5}, true));
}
