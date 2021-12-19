#ifndef GOAT_ENGINE_COLLIDER_HPP
#define GOAT_ENGINE_COLLIDER_HPP

#include "../GameComponent.hpp"
#include <vector>

namespace Engine {

    enum class ColliderType {
        NONE = 0,
        BOX_COLLIDER = 1,
        BOX_SENSOR = 2,
        CIRCLE_COLLIDER = 3,
        CIRCLE_SENSOR = 4,
        OVAL_COLLIDER = 5
    };

    class Collider : public GameComponent {
        public:
            Collider(bool active, double friction, double bounciness, double offSetX, double offSetY, ColliderType type);
            Collider(); // Default constructor for objects that don't need an active collider
            virtual ~Collider(); // Enforce C++ polymorphism
            ColliderType type{ColliderType::NONE};
            [[nodiscard]] std::vector<double> getData() const;

        protected:
            std::vector<double> _data{};
    };
}

#endif //GOAT_ENGINE_COLLIDER_HPP
