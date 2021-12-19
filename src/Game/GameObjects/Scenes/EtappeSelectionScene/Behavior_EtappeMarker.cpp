#include "Behavior_EtappeMarker.hpp"
#include "../../../Keys.hpp"
#include "Script_EtappeMarkerConfigurator.hpp"

Behavior_EtappeMarker::Behavior_EtappeMarker(Object_EtappeMarker& etappeMarker, int levelNumber, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::ETAPPE_CONFIG, std::make_shared<Script_EtappeMarkerConfigurator>(etappeMarker,levelNumber,true)));
}
