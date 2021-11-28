#ifndef GOAT_ENGINE_COLLISIONTESTSCRIPT_HPP
#define GOAT_ENGINE_COLLISIONTESTSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class CollisionTestScript : public Script {
    public:
        explicit CollisionTestScript(bool active);
        void OnTriggerEnter2D(GameObject& other) override;
        void OnTriggerStay2D(GameObject& other) override;
        void OnTriggerExit2D(GameObject& other) override;
    private:
        // Globals
        Debug& _debug = Debug::GetInstance();
};


#endif //GOAT_ENGINE_COLLISIONTESTSCRIPT_HPP
