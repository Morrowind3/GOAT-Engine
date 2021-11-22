//
// Created by MDstu on 22/11/2021.
//

#ifndef GOAT_ENGINE_RIGIDBODY_HPP
#define GOAT_ENGINE_RIGIDBODY_HPP

#include "../GameComponent.hpp"


namespace Engine {
    enum class BodyType {
        STATIC,
        KINEMATIC,
        DYNAMIC
    };

    class RigidBody : public GameComponent {
    public:
        RigidBody(double mass, double gravityScale, BodyType bodyType, bool isActive);

        double mass;
        double gravityScale;
        BodyType bodyType;
    };
}
#endif //GOAT_ENGINE_RIGIDBODY_HPP
