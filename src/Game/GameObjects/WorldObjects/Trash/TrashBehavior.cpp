#include "TrashBehavior.hpp"
#include "../../../Keys.hpp"
#include "TrashScript.hpp"

TrashBehavior::TrashBehavior(Trash& trash, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::TRASH, std::make_shared<TrashScript>( trash, true )));
}
