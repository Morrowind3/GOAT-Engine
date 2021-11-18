#include "System.hpp"

using namespace Engine;

System::System(const Scene* scene) : _scene(scene) {
}

std::vector<GameObject*> System::activeObjects() const {
    std::vector<GameObject*> activeObjects {};
    for (auto& gameObject : _scene->gameObjects) {
        if (gameObject->active) activeObjects.push_back(gameObject);
    }
    return activeObjects;
}
