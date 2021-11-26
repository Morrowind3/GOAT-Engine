#include "EtappeTwo.hpp"

#include "../../GameObjects/Meta/Etappes/EtappeTwoManager.hpp"
#include "../../Keys.hpp"

EtappeTwo::EtappeTwo(SceneManager& manager) : SharedEtappe(Keys::ETAPPE_TWO, Transform{Point{100,890},1,0,5,5},
        "Maps/etappe2.map", 21, 50, 250, 4, 0, -3000) {
    gameObjects.emplace_back(std::make_shared<EtappeTwoManager>(
            Transform{Point{0,0},0}, true));
}
