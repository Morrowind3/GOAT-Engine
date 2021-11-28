#ifndef GOAT_ENGINE_COLLIDER_HPP
#define GOAT_ENGINE_COLLIDER_HPP

#include "../GameComponent.hpp"
#include <vector>

namespace Engine {

    enum class ColliderType {
        NONE = 0,
        BOX_COLLIDER = 1,
        CIRCLE_COLLIDER = 2,
    };

    class Collider : public GameComponent {
        public:
            Collider(bool active, ColliderType type);
            Collider(); // Default constructor for objects that don't need an active collider
            virtual ~Collider(); // Enforce C++ polymorphism

            ColliderType type{ColliderType::NONE};

            [[nodiscard]] std::vector<double> GetData() const;

            // TODO: Only accessible by classes that explicitly need this
            std::vector<double> _data{};
    };
}

#endif //GOAT_ENGINE_COLLIDER_HPP
