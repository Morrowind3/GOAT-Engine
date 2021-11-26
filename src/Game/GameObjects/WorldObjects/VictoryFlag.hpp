//
// Created by Morrowind3 on 26/11/2021.
//


#ifndef GOAT_ENGINE_VICTORYFLAG_HPP
#define GOAT_ENGINE_VICTORYFLAG_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../Characters/Player.hpp"

using namespace Engine;

class VictoryFlag : public GameObject {
    public: VictoryFlag(Transform transform, const std::shared_ptr<Player>& player, bool active);
};


#endif //GOAT_ENGINE_VICTORYFLAG_HPP
