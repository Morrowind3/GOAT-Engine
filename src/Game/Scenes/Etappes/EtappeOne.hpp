#ifndef GOAT_ENGINE_ETAPPEONE_HPP
#define GOAT_ENGINE_ETAPPEONE_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"
#include "../../GameObjects/Meta/EtappeOneManager.hpp"
#include "../../GameObjects/Tiles/SolidTile.hpp"

using namespace Engine;

class EtappeOne : public Scene {
    public:
        EtappeOne() : Scene("Etappe one") {
            gameObjects.emplace_back(new EtappeOneManager{Transform{Point{0,0},0,0,18,18}, true});
            gameObjects.emplace_back(new Player{Transform{Point{100,200},2,0,5,5},true});
            gameObjects.emplace_back(new Goat{Transform{Point{1000,50},3,0,5,5},true});
            gameObjects.emplace_back(new SolidTile{"Sprites/landscapes/grass/grass_ground_flat.png",Transform{Point{100,500},1,0,5,5},true });
            gameObjects.emplace_back(new SolidTile{"Sprites/landscapes/grass/grass_ground_flat.png",Transform{Point{1000,600},1,0,5,5},true });

        }
};

#endif //GOAT_ENGINE_ETAPPEONE_HPP
