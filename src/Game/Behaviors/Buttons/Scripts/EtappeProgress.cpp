#include "EtappeProgress.hpp"
#include "../../../Keys.hpp"

EtappeProgress::EtappeProgress(bool active) : Script(active) {
}

void EtappeProgress::OnStart() {
    if (!_globals.gameExists(Keys::ETAPPE_SELECT)) _globals.gameStore(Keys::ETAPPE_SELECT, "2");
}
