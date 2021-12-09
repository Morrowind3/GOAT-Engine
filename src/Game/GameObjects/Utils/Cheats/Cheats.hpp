#ifndef GOAT_ENGINE_CHEATS_HPP
#define GOAT_ENGINE_CHEATS_HPP

#include "../../../../Engine/SceneManager.hpp"
#include "../../Player/Object_Player.hpp"

using namespace Engine;

class Cheats : public GameObject {
    public: explicit Cheats(Scene& scene, Object_Player& player, bool active);
};

#endif //GOAT_ENGINE_CHEATS_HPP
