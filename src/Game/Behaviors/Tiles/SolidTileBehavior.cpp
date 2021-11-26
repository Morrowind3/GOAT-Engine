#include "SolidTileBehavior.hpp"
#include "../../../Engine/Utilities/Debug.hpp"

SolidTileBehavior::SolidTileBehavior(SolidTile& self, bool active): Behavior(active) {
    Debug::GetInstance().log("Solid Tile Behavior TODO (sent from behavior construction)");
}
