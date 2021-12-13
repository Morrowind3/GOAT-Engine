#ifndef GOAT_ENGINE_SCRIPT_CHEATS_HPP
#define GOAT_ENGINE_SCRIPT_CHEATS_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Input.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class Script_Cheats : public Script {
    public:
        Script_Cheats(std::map<std::string,Text>& textObjects, bool active);
        void onUpdate(double deltaTime);

    private:
        bool _visible {false};
        std::map<std::string,Text>& _textObjects;
        Input& _input = Input::getInstance();
        std::string _filterKey{"CHEATS"};
};


#endif //GOAT_ENGINE_SCRIPT_CHEATS_HPP
