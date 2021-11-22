//
// Created by Stijn van Loon on 19-11-2021.
//

#ifndef GOAT_ENGINE_ETAPPETWO_HPP
#define GOAT_ENGINE_ETAPPETWO_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Meta/EtappeTwoManager.hpp"

using namespace Engine;

class EtappeTwo : public Scene {
public:
    EtappeTwo() : Scene("Etappe two") {
//        gameObjects.emplace_back(new EtappeOneManager{Transform{Point{0,0},0,0,18,18}, true});
//        gameObjects.emplace_back(new Player{Transform{Point{100,912},1,0,5,5},true});
//        gameObjects.emplace_back(new Goat{Transform{Point{100,912},3,0,5,5},true});

        gameObjects.emplace_back(new EtappeTwoManager{Transform{Point{0, 0}, 10, 0, 1, 1}, true});
    }
};

#endif //GOAT_ENGINE_ETAPPETWO_HPP
