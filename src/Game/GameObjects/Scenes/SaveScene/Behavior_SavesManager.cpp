#include "Behavior_SavesManager.hpp"
#include "../../../Keys.hpp"
#include "Script_LoadSaves.hpp"

Behavior_SavesManager::Behavior_SavesManager(bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_LoadSaves>(true)));
}
