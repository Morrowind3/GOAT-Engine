//
// Created by MDstu on 22/11/2021.
//

#include "RigidBody.hpp"

using namespace Engine;

RigidBody::RigidBody(double mass, double gravityScale, BodyType bodyType, bool active) : GameComponent(active), mass(mass), gravityScale(gravityScale), bodyType(bodyType) {}