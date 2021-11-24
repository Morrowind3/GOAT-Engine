#include "EtappeOne.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"
#include "../../GameObjects/Meta/EtappeOneManager.hpp"
#include "../../GameObjects/Meta/FpsDisplay.hpp"

EtappeOne::EtappeOne(SceneManager& manager) : Scene(Keys::ETAPPE_ONE) {
    gameObjects.emplace_back(std::make_shared<FpsDisplay>(true));
    gameObjects.emplace_back(std::make_shared<EtappeOneManager>(
            Transform{Point{0,0},0,0,18,18}, true));
    gameObjects.emplace_back(std::make_shared<Player>(
            Transform{Point{100,912},1,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<Goat>(
            Transform{Point{100,912},3,0,5,5},true));
}
