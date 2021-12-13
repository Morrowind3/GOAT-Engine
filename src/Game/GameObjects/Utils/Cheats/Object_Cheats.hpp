#ifndef GOAT_ENGINE_OBJECT_CHEATS_HPP
#define GOAT_ENGINE_OBJECT_CHEATS_HPP

#include "../../../../Engine/SceneManager.hpp"
#include "../../Player/Object_Player.hpp"

using namespace Engine;

class Object_Cheats : public GameObject {
    public: explicit Object_Cheats(Scene& scene, Object_Player& player, bool active);
};

#endif //GOAT_ENGINE_OBJECT_CHEATS_HPP
