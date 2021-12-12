//
// Created by Morrowind3 on 08/12/2021.
//

#ifndef GOAT_ENGINE_CLOUDBEHAVIOR_HPP
#define GOAT_ENGINE_CLOUDBEHAVIOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Cloud.hpp"

using namespace Engine;

class CloudBehavior : public Behavior {
public: CloudBehavior(Cloud& cloud, bool active);

};


#endif //GOAT_ENGINE_CLOUDBEHAVIOR_HPP
