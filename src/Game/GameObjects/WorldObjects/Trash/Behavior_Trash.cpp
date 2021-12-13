#include "Behavior_Trash.hpp"
#include "../../../Keys.hpp"
#include "Script_Trash.hpp"

Behavior_Trash::Behavior_Trash(Object_Trash& trash, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::TRASH, std::make_shared<Script_Trash>( trash, true )));
}
