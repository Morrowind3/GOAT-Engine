#include "Scene_EtappeThree.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/Etappes/EtappeThreeScene/Object_EtappeThreeManager.hpp"
#include "../../GameObjects/Utils/Timer/Object_TimerLine.hpp"

Scene_EtappeThree::Scene_EtappeThree() : SceneTemplate_Etappe(Keys::ETAPPE_THREE, {999999,999999}, // TODO: Dimensions
                                                           "Maps/Etappe3.map", 21, 50, 256, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<Object_EtappeThreeManager>(
            Transform{Point{0, -242}, LAYER::PARALLAX_BACKGROUND, 0,0, 20, 20}, true));
    gameObjects.emplace_back(std::make_shared<Object_TimerLine>(5,Transform{{0,-3500},LAYER::TIMER_LINE,1, 0, 3, 80}, true ));
}
