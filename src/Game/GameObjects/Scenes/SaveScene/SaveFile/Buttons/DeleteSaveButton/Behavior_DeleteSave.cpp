#include "Behavior_DeleteSave.hpp"
#include "../../../../../../Keys.hpp"
#include "Script_DeleteSave.hpp"

Behavior_DeleteSave::Behavior_DeleteSave(int saveNumber, Script& loadSavesScript, AudioSource& deleteSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_DeleteSave>(saveNumber, loadSavesScript, deleteSound, true)));
}
