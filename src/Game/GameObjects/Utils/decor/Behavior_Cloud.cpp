#include "Behavior_Cloud.hpp"
#include "Script_Cloud.hpp"
#include "../../../Keys.hpp"

Behavior_Cloud::Behavior_Cloud(Object_Cloud& cloud, bool active) : Behavior(active){
    scripts.insert(std::make_pair(Keys::CLOUDS, std::make_shared<Script_Cloud>(cloud, true)));
}
