#include "EtappeOne.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"
#include "../../GameObjects/Meta/Etappes/EtappeOneManager.hpp"
#include "../../GameObjects/Tiles/SolidTile.hpp"


EtappeOne::EtappeOne(SceneManager& manager) : SharedEtappe(Keys::ETAPPE_ONE, Transform{Point{100,912},1,0,5,5},
                                                           "Maps/etappe2.map", 21, 50, 250, 2, 0, -1000) {
    gameObjects.emplace_back(std::make_shared<EtappeOneManager>(
            Transform{Point{0,0},0,0,18,18}, true));
    gameObjects.emplace_back(std::make_shared<Goat>(
            Transform{Point{100,912},3,0,5,5},true));
    // TODO: Delete these two:
    gameObjects.emplace_back(std::make_shared<SolidTile>("Sprites/enemies/goat/goat_attack_stance.png",
            Transform{Point{940,750},2,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<SolidTile>("Sprites/enemies/goat/goat_attack_stance.png",Transform{Point{700,500},3,0,10,5},true));
}
