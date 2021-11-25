#include "EtappeMarkerBehavior.hpp"
#include "../Keys.hpp"
#include "Scripts/Progress/EtappeProgress.hpp"
#include "Scripts/Progress/EtappeMarkerConfigurator.hpp"

EtappeMarkerBehavior::EtappeMarkerBehavior(EtappeMarker& etappeMarker, int levelNumber, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::ETAPPE_PROGRESS, std::make_shared<EtappeProgress>(true)));
    scripts.insert(std::make_pair(Keys::ETAPPE_CONFIG, std::make_shared<EtappeMarkerConfigurator>(etappeMarker,levelNumber,true)));
}
