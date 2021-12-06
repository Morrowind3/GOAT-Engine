//
// Created by Morrowind3 on 06/12/2021.
//

#ifndef GOAT_ENGINE_TRASHCOUNTERSCRIPT_HPP
#define GOAT_ENGINE_TRASHCOUNTERSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class TrashCounterScript : public Script {
public:
    TrashCounterScript(Text& trashText, bool active): Script(active), _text(trashText){};
    void onUpdate(double deltaTime) override;
private:
    Text& _text;
    std::string _total;
    std::string _currentTrash;
};


#endif //GOAT_ENGINE_TRASHCOUNTERSCRIPT_HPP
