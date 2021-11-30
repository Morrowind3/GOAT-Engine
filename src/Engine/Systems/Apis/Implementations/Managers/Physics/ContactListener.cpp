#include "ContactListener.hpp"
#include <iostream>

using namespace Engine;
using State = CollisionState;

void ContactListener::flushForNextFrame() {
    for(auto& gameObjectParent : _tracked) {
        for(auto& gameObjectChild : gameObjectParent.second) {
            if (gameObjectChild.second == State::START_COLLIDING) {
                gameObjectChild.second = State::KEEP_COLLIDING;
            }
            if (gameObjectChild.second == State::STOP_COLLIDING) {
                gameObjectChild.second = State::NOT_COLLIDING;
            }
        }
    }
}

static std::pair<GameObject*,GameObject*> getGameObjects(b2Contact* contact) {
    auto* gameObjectA = (GameObject*) contact->GetFixtureA()->GetBody()->GetUserData();
    auto* gameObjectB = (GameObject*) contact->GetFixtureB()->GetBody()->GetUserData();
    if (!gameObjectA || !gameObjectB) {
        throw std::runtime_error("Contact Listener: one of the colliders does not have user data");
    }
    return {gameObjectA,gameObjectB};
}

static void insertStartCollision(GameObject* a, GameObject* b, std::map<GameObject*,std::map<GameObject*, CollisionState>>& tracked) {
    auto ensureGameObjectIsTracked = tracked.insert(std::make_pair(a,std::map<GameObject*,CollisionState>{}));
    auto& nestedArray = ensureGameObjectIsTracked.first->second;
    auto checkIfOtherGameObjectIsTracked = nestedArray.find(b);
    bool shouldInsert;
    if (checkIfOtherGameObjectIsTracked == nestedArray.end()) { // Implicit NOT_COLLIDING state
        shouldInsert = true;
    }
    else {
        shouldInsert =     checkIfOtherGameObjectIsTracked->second != CollisionState::START_COLLIDING &&
        /*Illegal states*/ checkIfOtherGameObjectIsTracked->second != CollisionState::KEEP_COLLIDING;
    }
    if (shouldInsert) {
        nestedArray[b] = CollisionState::START_COLLIDING;
    }
}

void ContactListener::BeginContact(b2Contact* contact) {
    auto gameObjects = getGameObjects(contact);

    if(!gameObjects.second->tags.empty() && gameObjects.first->collider.type == ColliderType::BOX_SENSOR){
        std::cout << "Player collided with a sensor" << std::endl;
    }

    insertStartCollision(gameObjects.first, gameObjects.second, _tracked); // A => B
    insertStartCollision(gameObjects.second, gameObjects.first, _tracked); // B => A
}

static void insertEndCollision(GameObject* a, GameObject* b, std::map<GameObject*,std::map<GameObject*, CollisionState>>& tracked) {
    auto ensureGameObjectIsTracked = tracked.insert(std::make_pair(a,std::map<GameObject*,CollisionState>{}));
    auto& nestedArray = ensureGameObjectIsTracked.first->second;
    auto checkIfOtherGameObjectIsTracked = nestedArray.find(b);
    bool shouldInsert;
    if (checkIfOtherGameObjectIsTracked == nestedArray.end()) { // Implicit NOT_COLLIDING state
        shouldInsert = false;
    }
    else {
        shouldInsert =     checkIfOtherGameObjectIsTracked->second != CollisionState::STOP_COLLIDING &&
        /*Illegal states*/ checkIfOtherGameObjectIsTracked->second != CollisionState::NOT_COLLIDING;
    }
    if (shouldInsert) {
        nestedArray[b] = CollisionState::STOP_COLLIDING;
    }
}

void ContactListener::EndContact(b2Contact* contact) {
    auto gameObjects = getGameObjects(contact);
    insertEndCollision(gameObjects.first, gameObjects.second, _tracked); // A => B
    insertEndCollision(gameObjects.second, gameObjects.first, _tracked); // B => A
}

// This gets called by the scripting system
void ContactListener::runCollisionScripts() {
    for (auto& gameObject : _tracked) {
        for (auto& collision : gameObject.second) {

            if (collision.second == State::START_COLLIDING) {
                for (auto& behavior : gameObject.first->behaviors) {
                    if (behavior.second->active) behavior.second->onTriggerEnter2D(*collision.first);
                }
            }

            if (collision.second == State::KEEP_COLLIDING) {
                for (auto& behavior : gameObject.first->behaviors) {
                    if (behavior.second->active) behavior.second->onTriggerStay2D(*collision.first);
                }
            }

            if (collision.second == State::STOP_COLLIDING) {
                for (auto& behavior : gameObject.first->behaviors) {
                    if (behavior.second->active) behavior.second->onTriggerExit2D(*collision.first);
                }
            }

        }
    }
}


