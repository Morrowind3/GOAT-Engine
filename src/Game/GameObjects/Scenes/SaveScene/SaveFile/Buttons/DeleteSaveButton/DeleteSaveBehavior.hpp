#ifndef GOAT_ENGINE_DELETESAVEBEHAVIOR_HPP
#define GOAT_ENGINE_DELETESAVEBEHAVIOR_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../../../../Engine/API/GameObjects/GameComponents/Render/Sprite.hpp"
#include "../../../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class DeleteSaveBehavior: public Behavior {
    public: DeleteSaveBehavior(int saveNumber, Script& loadSavesScript, AudioSource& deleteSound, bool active);
};


#endif //GOAT_ENGINE_DELETESAVEBEHAVIOR_HPP
