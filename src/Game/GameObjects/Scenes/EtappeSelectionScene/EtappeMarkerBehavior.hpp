#ifndef GOAT_ENGINE_ETAPPEMARKERBEHAVIOR_HPP
#define GOAT_ENGINE_ETAPPEMARKERBEHAVIOR_HPP

#include "./EtappeMarker.hpp"

using namespace Engine;

class EtappeMarkerBehavior : public Behavior {
    public: EtappeMarkerBehavior(EtappeMarker& etappeMarker, int levelNumber, bool active);
};


#endif //GOAT_ENGINE_ETAPPEMARKERBEHAVIOR_HPP
