#ifndef GOAT_ENGINE_CHEATS_HPP
#define GOAT_ENGINE_CHEATS_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/API/Scene.hpp"
#include "../Characters/Player.hpp"

using namespace Engine;

class Cheats : public GameObject {
    public: explicit Cheats(Scene& scene, Player& player, bool active);
};

#endif //GOAT_ENGINE_CHEATS_HPP
