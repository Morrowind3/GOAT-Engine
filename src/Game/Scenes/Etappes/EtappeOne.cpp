#include "EtappeOne.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Meta/Etappes/EtappeOneManager.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Meta/Etappes/EtappeOneText.hpp"

EtappeOne::EtappeOne(SceneManager& manager) : SharedEtappe(Keys::ETAPPE_ONE,manager, {999999,999999}, // TODO: Dimensions
                                                           "Maps/Etappe1.map", 21, 50, 250, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<EtappeOneManager>(
            Transform{Point{0, -242}, LAYER::PARALLAX_BACKGROUND, 0, 20, 20}, true));
    gameObjects.emplace_back(std::make_shared<EtappeOneText>(
            Transform{Point{0, -50}, LAYER::ETAPPE_TEXT, 0, 1, 1}, true));
}
