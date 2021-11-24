//
// Created by MDstu on 24/11/2021.
//

#include "CollisionManager.hpp"


using namespace Engine;


CollisionManager::CollisionManager() : _bodies(std::map<std::string, b2Body>()){}

void CollisionManager::storeBody(const std::string &bodyName, b2Body &body) {

}