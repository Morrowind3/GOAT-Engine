#ifndef GOAT_ENGINE_SCRIPT_ETAPPEMARKERCONFIGURATOR_HPP
#define GOAT_ENGINE_SCRIPT_ETAPPEMARKERCONFIGURATOR_HPP

#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"
#include "Object_EtappeMarker.hpp"

class Script_EtappeMarkerConfigurator : public Script {
    public:
        Script_EtappeMarkerConfigurator(Object_EtappeMarker& etappeMarker, int levelNumber, bool active);
        void onStart();
    private:
        // Globals
        Globals& _globals = Globals::getInstance();
        Debug& _debug = Debug::getInstance();
        // Variables
        Object_EtappeMarker& _etappeMarker;
        int _levelNumber;
};


#endif //GOAT_ENGINE_SCRIPT_ETAPPEMARKERCONFIGURATOR_HPP
