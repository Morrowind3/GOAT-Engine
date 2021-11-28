#include "EtappeTwo.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Meta/Etappes/EtappeTwoManager.hpp"
#include "../../Keys.hpp"

EtappeTwo::EtappeTwo(SceneManager& manager) : SharedEtappe(Keys::ETAPPE_TWO, Transform{Point{100,700}, LAYER::CHARACTER,0,5,5}, manager,
        "Maps/Etappe2.map", 21, 50, 250, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<EtappeTwoManager>(
            Transform{Point{0,0},0}, true));
}
