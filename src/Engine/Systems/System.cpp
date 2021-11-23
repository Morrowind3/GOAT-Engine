#include "System.hpp"

using namespace Engine;

System::System(const Scene* scene) : _scene(scene) {
}

std::vector<std::shared_ptr<GameObject>> System::activeObjects() const {
    std::vector<std::shared_ptr<GameObject>> activeObjects {};
    for (auto& gameObject : _scene->gameObjects) {
        if (gameObject->active) activeObjects.push_back(gameObject);
    }
    return activeObjects;
}
