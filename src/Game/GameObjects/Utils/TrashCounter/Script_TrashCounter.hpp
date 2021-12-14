#ifndef GOAT_ENGINE_SCRIPT_TRASHCOUNTER_HPP
#define GOAT_ENGINE_SCRIPT_TRASHCOUNTER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Script_TrashCounter : public Script {
public:
    Script_TrashCounter(Text& trashText, bool active): Script(active), _text(trashText){};
    void onUpdate(double deltaTime) override;
private:
    Text& _text;
    std::string _total;
    std::string _currentTrash;
};


#endif //GOAT_ENGINE_SCRIPT_TRASHCOUNTER_HPP