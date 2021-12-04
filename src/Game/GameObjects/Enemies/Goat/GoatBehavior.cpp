#include "GoatBehavior.hpp"
#include "../../../Keys.hpp"
#include "GoatScript.hpp"

GoatBehavior::GoatBehavior(Goat& goat, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::GOAT, std::make_shared<GoatScript>(goat, true)));
}
