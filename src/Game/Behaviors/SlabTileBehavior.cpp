#include "SlabTileBehavior.hpp"
#include "Scripts/SlabTileScript.hpp"
#include "../Keys.hpp"

SlabTileBehavior::SlabTileBehavior(SlabTile& self, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<SlabTileScript>(self, true)));
}
