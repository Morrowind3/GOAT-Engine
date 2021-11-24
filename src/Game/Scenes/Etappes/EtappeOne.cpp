#include "EtappeOne.hpp"

EtappeOne::EtappeOne(SceneManager& manager) : Scene(Keys::ETAPPE_ONE) {
    gameObjects.emplace_back(new EtappeOneManager{Transform{Point{0,0},0,0,18,18}, true});
    gameObjects.emplace_back(new Player{Transform{Point{100,912},1,0,5,5},true});
    gameObjects.emplace_back(new Goat{Transform{Point{100,912},3,0,5,5},true});
}
