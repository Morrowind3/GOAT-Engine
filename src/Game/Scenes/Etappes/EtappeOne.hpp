#ifndef GOAT_ENGINE_ETAPPEONE_HPP
#define GOAT_ENGINE_ETAPPEONE_HPP

#include <memory>
#include <vector>

#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Characters/Player.hpp"

using namespace Engine;

class EtappeOne : public Scene {
    public:
        EtappeOne() : Scene("Etappe one") {
            _player = std::make_unique<Player>(Transform{Point{100,100},0,1,1,Engine::FLIP::FLIP_NONE});
            gameObjects.emplace_back(_player.get());
        }
    private:
        std::unique_ptr<Player> _player {};
};

#endif //GOAT_ENGINE_ETAPPEONE_HPP
