#include "EtappeTwo.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Meta/Etappes/EtappeTwoManager.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Meta/TimerLine.hpp"
#include "../../GameObjects/Meta/Etappes/EtappeTwoText.hpp"

EtappeTwo::EtappeTwo(SceneManager& manager) : SharedEtappe(Keys::ETAPPE_TWO, manager,
        "Maps/Etappe2.map", 21, 50, 250, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<EtappeTwoManager>(
            Transform{Point{0, -242}, LAYER::PARALLAX_BACKGROUND, 0, 20, 20}, true));
    gameObjects.emplace_back(std::make_shared<TimerLine>(6,Transform{{0,-3500},LAYER::TILES_FRONT+1, 0, 3, 80}, true ));
    gameObjects.emplace_back(std::make_shared<EtappeTwoText>(
            Transform{Point{0, -50}, LAYER::ETAPPE_TEXT, 0, 1, 1}, true));

}
