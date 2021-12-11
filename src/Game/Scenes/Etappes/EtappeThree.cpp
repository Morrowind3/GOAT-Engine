#include "EtappeThree.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/Etappes/EtappeThreeScene/EtappeThreeManager.hpp"
#include "../../GameObjects/Utils/Timer/TimerLine.hpp"

EtappeThree::EtappeThree() : SharedEtappe(Keys::ETAPPE_ONE, {999999,999999}, // TODO: Dimensions
                                                           "Maps/Etappe3.map", 21, 50, 250, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<EtappeThreeManager>(
            Transform{Point{0, -242}, LAYER::PARALLAX_BACKGROUND, 0,0, 20, 20}, true));
    gameObjects.emplace_back(std::make_shared<TimerLine>(5,Transform{{0,-3500},LAYER::TIMER_LINE,1, 0, 3, 80}, true ));
}
