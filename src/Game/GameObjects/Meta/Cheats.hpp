#ifndef GOAT_ENGINE_CHEATS_HPP
#define GOAT_ENGINE_CHEATS_HPP

#include "../Characters/Object_Player.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class Cheats : public GameObject {
    public: explicit Cheats(SceneManager& sceneManager, Scene& scene, Object_Player& player, bool active);
};

#endif //GOAT_ENGINE_CHEATS_HPP
