#include "Behavior_Etappe.hpp"
#include "../../../Keys.hpp"
#include "../../Utils/Cheats/CheatsLibrary/Script_Pause.hpp"
#include "Script_LifeInit.hpp"

Behavior_Etappe::Behavior_Etappe(int startHpAmount, AudioSource& pauseSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<Script_LifeInit>(startHpAmount, true)));
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<Script_Pause>(pauseSound,true)));
}
