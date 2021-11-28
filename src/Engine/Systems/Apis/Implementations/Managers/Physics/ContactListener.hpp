#ifndef GOAT_ENGINE_CONTACTLISTENER_HPP
#define GOAT_ENGINE_CONTACTLISTENER_HPP

#include <map>
#include <Dynamics/b2WorldCallbacks.h>
#include <Dynamics/Contacts/b2Contact.h>
#include "../../../../../API/GameObjects/GameObject.hpp"
#include "CollisionState.hpp"

namespace Engine {
    class ContactListener : public b2ContactListener  {
        public:
            void flushForNextFrame();
            void runCollisionScripts();
        private:
            void BeginContact(b2Contact* contact) override;
            void EndContact(b2Contact* contact) override;
            std::map<GameObject*,std::map<GameObject*,CollisionState>> _tracked{};
    };
}

#endif //GOAT_ENGINE_CONTACTLISTENER_HPP
