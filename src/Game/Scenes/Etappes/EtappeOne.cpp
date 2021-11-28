#include "EtappeOne.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"
#include "../../GameObjects/Meta/Etappes/EtappeOneManager.hpp"
#include "../../GameObjects/Tiles/SolidTile.hpp"
#include "../../GameObjects/WorldObjects/VictoryFlag.hpp"


EtappeOne::EtappeOne(SceneManager& manager) : SharedEtappe(Keys::ETAPPE_ONE, Transform{Point{100,800},1,0,5,5}, manager,
                                                           "Maps/etappe2.map", 21, 50, 250, 2, 0, -1000) {
    gameObjects.emplace_back(std::make_shared<EtappeOneManager>(
            Transform{Point{0,0},0,0,18,18}, true));
    gameObjects.emplace_back(std::make_shared<VictoryFlag>(
            Transform{Point{325,912},2,0,3,8}, _player, true));
}
