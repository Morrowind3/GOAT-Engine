#include "EtappeTwo.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/Etappes/EtappeTwoScene/EtappeTwoManager.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Utils/Timer/TimerLine.hpp"
#include "../../GameObjects/Scenes/Etappes/EtappeTwoScene/EtappeTwoText.hpp"

EtappeTwo::EtappeTwo(SceneManager& manager) : SharedEtappe(Keys::ETAPPE_TWO, manager, {999999,999999}, // TODO: Dimensions
        "Maps/Etappe2.map", 21, 50, 250, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<EtappeTwoManager>(
            Transform{Point{0, -242}, LAYER::PARALLAX_BACKGROUND, 0,0, 20, 20}, true));
    gameObjects.emplace_back(std::make_shared<TimerLine>(5,Transform{{0,-3500},LAYER::TIMER_LINE,1, 0, 3, 80}, true ));
    gameObjects.emplace_back(std::make_shared<EtappeTwoText>(
            Transform{Point{0, -50}, LAYER::ETAPPE_TEXT, 0, 0, 1, 1}, true));

}
