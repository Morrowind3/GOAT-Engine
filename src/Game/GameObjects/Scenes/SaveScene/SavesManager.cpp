#include "SavesManager.hpp"
#include "../../../Keys.hpp"
#include "SavesManagerBehavior.hpp"

SavesManager::SavesManager(Scene& scene, bool active): GameObject(Transform{{0,0}}, active) {
    behaviors.insert(std::make_pair(Keys::_, std::make_shared<SavesManagerBehavior>(scene,true)));
}
