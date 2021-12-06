#include "DefeatScene.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/DefeatBackground.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/SelectEtappeButton.hpp"
#include "../../GameObjects/Scenes/EtappeEndScene/RetryButton.hpp"


DefeatScene::DefeatScene(SceneManager& manager) : SceneTemplate_Menu(Keys::DEFEAT_SCREEN) {
    gameObjects.emplace_back(std::make_shared<DefeatBackground>(Transform{Point{0, 0}, 1, 0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<SelectEtappeButton>(
            manager, Transform{Point{560, 830}, 100, 0, 6, 5}, true));
    gameObjects.emplace_back(std::make_shared<RetryButton>(
            manager, Transform{Point{970, 830}, 100, 0, 6, 5}, true));
}
