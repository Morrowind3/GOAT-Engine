#ifndef GOAT_ENGINE_PAUSESCRIPT_HPP
#define GOAT_ENGINE_PAUSESCRIPT_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"
#include "../../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class PauseScript : public Script {
    public:
        PauseScript(bool active);
        void OnStart();
        void OnUpdate(double deltaTime);
        void OnExternalEvent();
        void OnDestroy();

    private:
        void pauseLogic();
        // Utilities
        Input& _input = Input::GetInstance();
        Debug& _debug = Debug::GetInstance();
        Globals& _globals = Globals::GetInstance();
        // Variables
        bool _isPaused = false; // Quick access bool
};


#endif //GOAT_ENGINE_PAUSESCRIPT_HPP
