//
// Created by MDstu on 22/11/2021.
//

#ifndef GOAT_ENGINE_COLLIDER_HPP
#define GOAT_ENGINE_COLLIDER_HPP

#include "../GameComponent.hpp"
#include <vector>

namespace Engine {
    enum class ColliderType{
        BOX_COLLIDER,
        CIRCLE_COLLIDER,
    };

    class Collider : public GameComponent {
    public:
        Collider(bool active, ColliderType type);
        Collider();
        virtual ~Collider();

        std::vector<double> GetData();

        ColliderType type;
        std::vector<double> _data{};

    };
}

#endif //GOAT_ENGINE_COLLIDER_HPP
