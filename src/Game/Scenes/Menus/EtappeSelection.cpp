#include "EtappeSelection.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Meta/EtappeSelection/EtappeMarker.hpp"
#include "../../GameObjects/Meta/EtappeSelection/EtappeSelectionBackground.hpp"
#include "../../GameObjects/Meta/EtappeSelection/BackToMenuButton.hpp"
#include "../../GameObjects/Meta/Hud/FpsMeter.hpp"

EtappeSelection::EtappeSelection(SceneManager& manager): SceneTemplate_StaticScreen(Keys::ETAPPE_SELECT) {
    // Etappe buttons (ordered from the base to the summit of the mountain)
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_ONE,1,1800,manager,
        Transform{{1100,780},100,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_TWO,2,3700,manager,
        Transform{{830,640},100,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_THREE,3,5000,manager,
        Transform{{1070,510},100,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_FOUR,4,6640,manager,
        Transform{{740,390},100,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_FIVE,5,8848,manager,
        Transform{{880,140},100,0,2.25,2.25},true));

    gameObjects.emplace_back(std::make_shared<BackToMenuButton>(
            manager, Transform{Point{20, 40}, 100, 0, 4, 4}, true));

    // TODO: Clouds swirling around the summit
    gameObjects.emplace_back(std::make_shared<EtappeSelectionBackground>(Transform{{0,0},1},true));
}
