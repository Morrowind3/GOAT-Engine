#include "EtappeMarkerBehavior.hpp"
#include "../../../Keys.hpp"
#include "EtappeMarkerConfigurator.hpp"

EtappeMarkerBehavior::EtappeMarkerBehavior(EtappeMarker& etappeMarker, int levelNumber, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::ETAPPE_CONFIG, std::make_shared<EtappeMarkerConfigurator>(etappeMarker,levelNumber,true)));
}
