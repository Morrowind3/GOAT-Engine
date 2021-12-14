#include "Behavior_TrashCounter.hpp"
#include "../../../Keys.hpp"
#include "../Timer/Script_Timer.hpp"
#include "Script_TrashCounter.hpp"

Behavior_TrashCounter::Behavior_TrashCounter(Text& trashText, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::TRASH ,std::make_shared<Script_TrashCounter>(trashText, true)));
}
