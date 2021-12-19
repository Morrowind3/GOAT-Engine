#include "Behavior_LavaTile.hpp"
#include "Script_LavaTile.hpp"
#include "../../../Keys.hpp"

Behavior_LavaTile::Behavior_LavaTile(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<Script_LavaTile>(true)));
}