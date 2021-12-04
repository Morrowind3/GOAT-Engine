#include "EtappeTwo.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Meta/Etappes/EtappeTwoManager.hpp"
#include "../../Keys.hpp"

EtappeTwo::EtappeTwo(SceneManager& manager) : SharedEtappe(Keys::ETAPPE_TWO, manager, {999999,999999}, // TODO: Dimensions
        "Maps/Etappe2.map", 21, 50, 250, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<EtappeTwoManager>(
            Transform{Point{0, -242}, LAYER::PARALLAX_BACKGROUND, 0, 20, 20}, true));
}
