#include "EtappeMarkerConfigurator.hpp"
#include "../../../Keys.hpp"

EtappeMarkerConfigurator::EtappeMarkerConfigurator(EtappeMarker& etappeMarker, int levelNumber, bool active):
        Script(active), _etappeMarker{etappeMarker}, _levelNumber{levelNumber} {
}

void EtappeMarkerConfigurator::onStart() {
    if (_globals.gameExists(Keys::ETAPPE_SELECT)) {
        int currentUnlockedLevel = std::stoi(_globals.gameGet(Keys::ETAPPE_SELECT));
        // Current level is unlocked
        if (currentUnlockedLevel >= _levelNumber) {
            _etappeMarker.buttons.at(Keys::TRUE).active = true;
            _etappeMarker.buttons.at(Keys::FALSE).active = false;
        }
        // Current level is the highest unlocked level
        if (currentUnlockedLevel == _levelNumber) {
            _etappeMarker.sprites.at(Keys::STAR).active = true;
        }
        // Current level is the next level
        if (currentUnlockedLevel+1 == _levelNumber) {
            _etappeMarker.sprites.at(Keys::FLAG).active = true;
        }
    } else _debug.log("(Etappe Marker Config) This shouldn't occur but key " + Keys::ETAPPE_SELECT + " wasn't loaded in game scope");
}
