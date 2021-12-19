#include "Behavior_PlaySave.hpp"
#include "../../../../../../Keys.hpp"
#include "Script_PlaySave.hpp"

Behavior_PlaySave::Behavior_PlaySave(int saveNumber, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_PlaySave>(saveNumber, true)));
}
