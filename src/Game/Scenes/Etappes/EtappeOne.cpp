#include "EtappeOne.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"
#include "../../GameObjects/Meta/EtappeOneManager.hpp"

EtappeOne::EtappeOne(SceneManager& manager) : Scene(Keys::ETAPPE_ONE) {
    // TODO: Shared ptr instead of new keyword!!!
    gameObjects.emplace_back(new EtappeOneManager{Transform{Point{0,0},0,0,18,18}, true});
    gameObjects.emplace_back(new Player{Transform{Point{100,912},1,0,5,5},true});
    gameObjects.emplace_back(new Goat{Transform{Point{100,912},3,0,5,5},true});
}
