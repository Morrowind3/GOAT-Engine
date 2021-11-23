#ifndef GOAT_ENGINE_ETAPPEONE_HPP
#define GOAT_ENGINE_ETAPPEONE_HPP

#include "../../Keys.hpp"
#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"
#include "../../GameObjects/Meta/EtappeOneManager.hpp"

using namespace Engine;

class EtappeOne : public Scene {
    public:
        EtappeOne() : Scene(Keys::ETAPPE_ONE) {
            gameObjects.emplace_back(new EtappeOneManager{Transform{Point{0,0},0,0,18,18}, true});
            gameObjects.emplace_back(new Player{Transform{Point{100,912},1,0,5,5},true});
            gameObjects.emplace_back(new Goat{Transform{Point{100,912},3,0,5,5},true});
        }
};

#endif //GOAT_ENGINE_ETAPPEONE_HPP
