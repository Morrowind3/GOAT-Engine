#ifndef GOAT_ENGINE_ETAPPEONE_HPP
#define GOAT_ENGINE_ETAPPEONE_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Characters/Player.hpp"

using namespace Engine;

class EtappeOne : public Scene {
    public:
        EtappeOne() : Scene("Etappe one") {
            gameObjects.emplace_back(new Player{Transform{Point{100,100},0,1,1,Engine::FLIP::FLIP_NONE}});
        }
};

#endif //GOAT_ENGINE_ETAPPEONE_HPP
