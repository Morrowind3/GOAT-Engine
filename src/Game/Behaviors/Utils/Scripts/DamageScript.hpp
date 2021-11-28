#ifndef GOAT_ENGINE_DAMAGESCRIPT_HPP
#define GOAT_ENGINE_DAMAGESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;


class DamageScript : public Script{
    public:
        explicit DamageScript(GameObject& actor, bool active): Script(active), _actor(actor){};
        void OnExternalEvent() override;
        void OnUpdate(double deltaTime) override;
        void OnDestroy() override;
    private:
        static const int GRACE_PERIOD = 1500;
        double _graceTimer = GRACE_PERIOD;
        GameObject& _actor;
};


#endif //GOAT_ENGINE_DAMAGESCRIPT_HPP
