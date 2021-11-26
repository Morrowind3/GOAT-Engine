#ifndef GOAT_ENGINE_ETAPPEMARKERCONFIGURATOR_HPP
#define GOAT_ENGINE_ETAPPEMARKERCONFIGURATOR_HPP

#include "../../../Engine/Utilities/Globals.hpp"
#include "../../../Engine/Utilities/Debug.hpp"
#include "../../../GameObjects/Meta/EtappeSelection/EtappeMarker.hpp"

class EtappeMarkerConfigurator : public Script {
    public:
        EtappeMarkerConfigurator(EtappeMarker& etappeMarker, int levelNumber, bool active);
        void OnStart();
    private:
        // Globals
        Globals& _globals = Globals::GetInstance();
        Debug& _debug = Debug::GetInstance();
        // Variables
        EtappeMarker& _etappeMarker;
        int _levelNumber;
};


#endif //GOAT_ENGINE_ETAPPEMARKERCONFIGURATOR_HPP
