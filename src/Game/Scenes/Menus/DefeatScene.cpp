#include "DefeatScene.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/DefeatBackground.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/SelectEtappeButton.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/RetryButton.hpp"
#include "../../Layers.hpp"

DefeatScene::DefeatScene() : SceneTemplate_Menu(Keys::DEFEAT_SCREEN) {
    gameObjects.emplace_back(std::make_shared<DefeatBackground>(Transform{Point{0, 0}, 0, 0,0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<SelectEtappeButton>(
            Transform{Point{560, 830}, LAYER::UI, 0,0, 6, 5}, true));
    gameObjects.emplace_back(std::make_shared<RetryButton>(
            Transform{Point{970, 830}, LAYER::UI, 0, 0, 6, 5}, true));
}
