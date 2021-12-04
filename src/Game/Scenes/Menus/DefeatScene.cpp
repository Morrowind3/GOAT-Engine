#include "DefeatScene.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Meta/MainMenu/Background.hpp"
#include "../../GameObjects/Meta/EtappeEnd/DefeatBackground.hpp"
#include "../../GameObjects/Meta/EtappeEnd/SelectEtappeButton.hpp"
#include "../../GameObjects/Meta/EtappeEnd/RetryButton.hpp"
#include "../../GameObjects/Meta/Hud/FpsMeter.hpp"

DefeatScene::DefeatScene(SceneManager& manager) : SceneTemplate_StaticScreen(Keys::DEFEAT_SCREEN) {
    gameObjects.emplace_back(std::make_shared<DefeatBackground>(Transform{Point{0, 0}, 1, 0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<SelectEtappeButton>(
            manager, Transform{Point{560, 830}, 100, 0, 6, 5}, true));
    gameObjects.emplace_back(std::make_shared<RetryButton>(
            manager, Transform{Point{970, 830}, 100, 0, 6, 5}, true));
}
