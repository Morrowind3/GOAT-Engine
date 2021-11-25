#include "EtappeOne.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"
#include "../../GameObjects/Meta/EtappeOneManager.hpp"
#include "../../GameObjects/Meta/FpsDisplay.hpp"
#include "../../GameObjects/Tiles/SolidTile.hpp"


EtappeOne::EtappeOne(SceneManager& manager) : Scene(Keys::ETAPPE_ONE) {
    _camera.AddWaypoint({0,400}, 2);
    _camera.AddWaypoint({500,400}, 3, 3.0);
    _camera.AddWaypoint({0,500}, 10, 1.0 );

//    _camera.AddWaypoint({400,800}, 15000);
//    _camera.AddWaypoint({200,200}, 400000);

    gameObjects.emplace_back(std::make_shared<FpsDisplay>(true));
    gameObjects.emplace_back(std::make_shared<EtappeOneManager>(
            Transform{Point{0,0},0,0,18,18}, true));
    gameObjects.emplace_back(std::make_shared<Player>(
            Transform{Point{100,912},1,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<Goat>(
            Transform{Point{100,912},3,0,5,5},true));

    gameObjects.emplace_back(std::make_shared<SolidTile>("Sprites/enemies/goat/goat_attack_stance.png",
            Transform{Point{940,750},2,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<SolidTile>("Sprites/enemies/goat/goat_attack_stance.png",Transform{Point{700,500},3,0,10,5},true));
}
