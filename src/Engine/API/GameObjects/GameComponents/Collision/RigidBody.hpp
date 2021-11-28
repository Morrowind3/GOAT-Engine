#ifndef GOAT_ENGINE_RIGIDBODY_HPP
#define GOAT_ENGINE_RIGIDBODY_HPP

#include "../GameComponent.hpp"


namespace Engine {

    enum class BodyType {
        STATIC = 1,
        KINEMATIC = 2,
        DYNAMIC = 3
    };

    class RigidBody : public GameComponent {
        public:
            RigidBody(double mass, double gravityScale, BodyType bodyType, bool isActive);
            RigidBody(); // Default constructor for objects that don't need an active rididbody

            double mass{0};
            double gravityScale{0};
            BodyType bodyType{BodyType::STATIC};
        float forceY;
        float forceX;
    };
}
#endif //GOAT_ENGINE_RIGIDBODY_HPP
