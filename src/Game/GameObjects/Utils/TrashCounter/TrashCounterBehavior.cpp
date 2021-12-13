#include "TrashCounterBehavior.hpp"
#include "../../../Keys.hpp"
#include "../Timer/TimerScript.hpp"
#include "TrashCounterScript.hpp"

TrashCounterBehavior::TrashCounterBehavior(Text& trashText, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::TRASH ,std::make_shared<TrashCounterScript>(trashText, true)));
}
