#ifndef GOAT_ENGINE_COLLIDER_HPP
#define GOAT_ENGINE_COLLIDER_HPP

#include "../GameComponent.hpp"
#include <vector>

namespace Engine {

    enum class ColliderType{
        NONE = 0,
        BOX_COLLIDER = 1,
        CIRCLE_COLLIDER = 2,
    };

    class Collider : public GameComponent {
    public:
        Collider(bool active, ColliderType type);
        Collider(); // Default constructor for objects that don't need an active collider
        virtual ~Collider(); // Enforce C++ polymorphism

        [[nodiscard]] std::vector<double> GetData() const;

        ColliderType type{ColliderType::NONE};
        std::vector<double> _data{}; // TODO: Only accessible by class that explicitly needs this

    };
}

#endif //GOAT_ENGINE_COLLIDER_HPP
