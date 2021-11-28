#ifndef GOAT_ENGINE_COLLISIONTESTSCRIPT_HPP
#define GOAT_ENGINE_COLLISIONTESTSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class CollisionTestScript : public Script {
    public:
        explicit CollisionTestScript(bool active);
        void onTriggerEnter2D(GameObject& other) override;
        void onTriggerStay2D(GameObject& other) override;
        void onTriggerExit2D(GameObject& other) override;
    private:
        // Globals
        Debug& _debug = Debug::getInstance();
};


#endif //GOAT_ENGINE_COLLISIONTESTSCRIPT_HPP
