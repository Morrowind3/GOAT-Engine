#include "EtappeProgress.hpp"
#include "../../../Keys.hpp"

EtappeProgress::EtappeProgress(bool active) : Script(active) {
}

void EtappeProgress::onStart() {
    if (!_globals.gameExists(Keys::ETAPPE_SELECT)) _globals.gameStore(Keys::ETAPPE_SELECT, "1");
}
