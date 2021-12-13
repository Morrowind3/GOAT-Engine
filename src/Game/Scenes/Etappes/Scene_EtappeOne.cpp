#include "Scene_EtappeOne.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/Etappes/EtappeOneScene/Object_EtappeOneManager.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/Etappes/EtappeOneScene/Object_EtappeOneText.hpp"

Scene_EtappeOne::Scene_EtappeOne() : SceneTemplate_Etappe(Keys::ETAPPE_ONE, {999999,999999}, // TODO: Dimensions
                                                           "Maps/Etappe1.map", 21, 50, 250, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<Object_EtappeOneManager>(
            Transform{Point{0, -242}, LAYER::PARALLAX_BACKGROUND, 0,0, 20, 20}, true));
    gameObjects.emplace_back(std::make_shared<Object_EtappeOneText>(
            Transform{Point{0, -75}, LAYER::ETAPPE_TEXT, 0,0, 1, 1}, true));
}
