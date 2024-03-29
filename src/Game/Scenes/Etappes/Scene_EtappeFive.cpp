#include "Scene_EtappeFive.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Utils/Timer/Object_TimerLine.hpp"
#include "../../GameObjects/Scenes/Etappes/EtappeFiveScene/Object_EtappeFiveManager.hpp"


Scene_EtappeFive::Scene_EtappeFive() : SceneTemplate_Etappe(Keys::ETAPPE_FIVE,
                                                             "Maps/Etappe5.map", 21, 50, 265, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<Object_TimerLine>(3,Transform{{0,-3500},LAYER::TIMER_LINE, 0, 0,3, 80}, true ));
    gameObjects.emplace_back(std::make_shared<Object_EtappeFiveManager>(
            Transform{Point{0, -342}, LAYER::PARALLAX_BACKGROUND, 0,0, 20, 20}, true));
}