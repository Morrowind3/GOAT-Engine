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
        RigidBody();

        double mass;
        double gravityScale;
        BodyType bodyType;

        float forceY;
        float forceX;
    };
}
#endif //GOAT_ENGINE_RIGIDBODY_HPP
