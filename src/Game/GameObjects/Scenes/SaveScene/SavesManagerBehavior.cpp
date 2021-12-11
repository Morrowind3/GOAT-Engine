#include "SavesManagerBehavior.hpp"
#include "../../../Keys.hpp"
#include "LoadSavesScript.hpp"

SavesManagerBehavior::SavesManagerBehavior(Scene& scene, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<LoadSavesScript>(scene, true)));
}
