#ifndef GOAT_ENGINE_PLAYER_HPP
#define GOAT_ENGINE_PLAYER_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Player : public GameObject {
    public: Player(Transform transform, bool active);
};

#endif //GOAT_ENGINE_PLAYER_HPP
