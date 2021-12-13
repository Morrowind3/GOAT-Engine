#include "Script_EtappeMarkerConfigurator.hpp"
#include "../../../Keys.hpp"

Script_EtappeMarkerConfigurator::Script_EtappeMarkerConfigurator(Object_EtappeMarker& etappeMarker, int levelNumber, bool active):
        Script(active), _etappeMarker{etappeMarker}, _levelNumber{levelNumber} {
}

void Script_EtappeMarkerConfigurator::onStart() {
    if (_globals.gameExists(Keys::ETAPPES_UNLOCKED)) {
        int currentUnlockedLevel = std::stoi(_globals.gameGet(Keys::ETAPPES_UNLOCKED));
        // Current level is unlocked
        if (currentUnlockedLevel >= _levelNumber) {
            _etappeMarker.buttons.at(Keys::TRUE).active = true;
            _etappeMarker.buttons.at(Keys::FALSE).active = false;
        }
        // Current level is the highest unlocked level
        if (currentUnlockedLevel == _levelNumber) {
            //_etappeMarker.sprites.at(Keys::STAR).active = true; // TODO: Star renders in an unreliable fashion
        }
        // Current level is the next level
        if (currentUnlockedLevel+1 == _levelNumber) {
            //_etappeMarker.sprites.at(Keys::FLAG).active = true; // TODO: Flag renders in an unreliable fashion
        }
    } else _debug.log("(Etappe Marker Config) This shouldn't occur but key " + Keys::ETAPPES_UNLOCKED + " wasn't loaded in game scope");
}
