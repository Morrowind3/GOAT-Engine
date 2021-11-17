#ifndef GOAT_ENGINE_ETAPPEONE_HPP
#define GOAT_ENGINE_ETAPPEONE_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"

using namespace Engine;

class EtappeOne : public Scene {
    public:
        EtappeOne() : Scene("Etappe one") {
            gameObjects.emplace_back(new Player{Transform{Point{100,100},1,0,5,5},true});
            gameObjects.emplace_back(new Goat{Transform{Point{100,100},3,0,5,5},true});
            gameObjects.emplace_back(new Player{Transform{Point{120,120},2,0,5,5},true});
        }
};

#endif //GOAT_ENGINE_ETAPPEONE_HPP
