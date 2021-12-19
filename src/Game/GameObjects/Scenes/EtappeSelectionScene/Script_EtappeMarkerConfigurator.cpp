#include "Script_EtappeMarkerConfigurator.hpp"
#include "../../../Keys.hpp"

Script_EtappeMarkerConfigurator::Script_EtappeMarkerConfigurator(Object_EtappeMarker& etappeMarker, int levelNumber, bool active):
        Script(active), _etappeMarker{etappeMarker}, _levelNumber{levelNumber} {
}

void Script_EtappeMarkerConfigurator::onStart() {
    _globals.gameRemove(Keys::TRASH_MAX);
    if (_globals.gameExists(Keys::ETAPPES_UNLOCKED)) {
        int currentUnlockedLevel = std::stoi(_globals.gameGet(Keys::ETAPPES_UNLOCKED));
        // Current level is unlocked
        if (currentUnlockedLevel >= _levelNumber) {
            _etappeMarker.buttons.at(Keys::TRUE).active = true;
            _etappeMarker.buttons.at(Keys::FALSE).active = false;
        }
    } else _debug.log("(Etappe Marker Config) This shouldn't occur but key " + Keys::ETAPPES_UNLOCKED + " wasn't loaded in game scope");
}
