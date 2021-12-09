#include "DeleteSaveBehavior.hpp"
#include "../../../../../../Keys.hpp"
#include "DeleteSaveScript.hpp"

DeleteSaveBehavior::DeleteSaveBehavior(int saveNumber, Script& loadSavesScript, AudioSource& deleteSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<DeleteSaveScript>(saveNumber, loadSavesScript, deleteSound, true)));
}
