#include "Scene_EtappeFour.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/Etappes/EtappeFourScene/Object_EtappeFourManager.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Utils/Timer/Object_TimerLine.hpp"


Scene_EtappeFour::Scene_EtappeFour() : SceneTemplate_Etappe(Keys::ETAPPE_FOUR,
                                                           "Maps/Etappe4.map", 21, 50, 256, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<Object_TimerLine>(5,Transform{{0,-3500},LAYER::TIMER_LINE, 0, 0,3, 80}, true ));
    gameObjects.emplace_back(std::make_shared<Object_EtappeFourManager>(
            Transform{Point{0, -242}, LAYER::PARALLAX_BACKGROUND, 0,0, 20, 20}, true));
}