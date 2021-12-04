#include "HawkBehavior.hpp"
#include "../../Keys.hpp"

HawkBehaviour::HawkBehaviour(Hawk& self, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::HAWK,std::make_shared<HawkScript>(self, true)));
}
