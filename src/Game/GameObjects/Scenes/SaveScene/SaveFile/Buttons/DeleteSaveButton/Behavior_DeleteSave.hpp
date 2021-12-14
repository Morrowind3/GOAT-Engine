#ifndef GOAT_ENGINE_BEHAVIOR_DELETESAVE_HPP
#define GOAT_ENGINE_BEHAVIOR_DELETESAVE_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../../../../Engine/API/GameObjects/GameComponents/Render/Sprite.hpp"
#include "../../../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Behavior_DeleteSave: public Behavior {
    public: Behavior_DeleteSave(int saveNumber, Script& loadSavesScript, AudioSource& deleteSound, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_DELETESAVE_HPP
