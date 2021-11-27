#ifndef GOAT_ENGINE_COLLISIONMANAGER_HPP
#define GOAT_ENGINE_COLLISIONMANAGER_HPP

#include "Box2D.h"

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include <vector>

namespace Engine {
    class CollisionManager {
        public:
        CollisionManager();
        void storeBody(const std::string &bodyName, b2Body &body);
    };
}

#endif //GOAT_ENGINE_COLLISIONMANAGER_HPP
