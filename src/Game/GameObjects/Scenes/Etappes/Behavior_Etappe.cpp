#include "Behavior_Etappe.hpp"
#include "../../../Keys.hpp"
#include "../../Utils/Cheats/CheatsLibrary/Script_Pause.hpp"
#include "Script_SceneInit.hpp"

Behavior_Etappe::Behavior_Etappe(unsigned short currentEtappe, unsigned short startHpAmount, AudioSource& pauseSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<Script_SceneInit>(currentEtappe, startHpAmount, true)));
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<Script_Pause>(pauseSound,true)));
}
