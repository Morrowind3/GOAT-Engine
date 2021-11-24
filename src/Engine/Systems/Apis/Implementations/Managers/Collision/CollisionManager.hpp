//
// Created by MDstu on 24/11/2021.
//

#ifndef GOAT_ENGINE_COLLISIONMANAGER_HPP
#define GOAT_ENGINE_COLLISIONMANAGER_HPP

#include "Box2D.h"

#include <map>
#include <memory>
#include <string>
#include <iostream>

namespace Engine {
    class CollisionManager {
        public:
        CollisionManager();
        void storeBody(const std::string &bodyName);

        private:
            std::unique_ptr<std::map<std::string, b2Body>> _bodies;
        };
}

#endif //GOAT_ENGINE_COLLISIONMANAGER_HPP
