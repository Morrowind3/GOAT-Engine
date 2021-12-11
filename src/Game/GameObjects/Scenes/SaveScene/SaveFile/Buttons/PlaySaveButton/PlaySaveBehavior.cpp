#include "PlaySaveBehavior.hpp"
#include "../../../../../../Keys.hpp"
#include "PlaySaveScript.hpp"

PlaySaveBehavior::PlaySaveBehavior(int saveNumber, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<PlaySaveScript>(saveNumber, true)));
}
