#ifndef GOAT_ENGINE_SNAKESCRIPT_HPP
#define GOAT_ENGINE_SNAKESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../GameObjects/Enemies/Snake.hpp"
#include "../../../GameObjects/Characters/Object_Player.hpp"
#include "../../../Scenes/Templates/SharedEtappe.hpp"

using namespace Engine;

class SnakeScript : public Script {
public:
    SnakeScript(Snake& snake, bool active) : Script(active), _snake(snake) {};
    void onTriggerEnter2D(GameObject &other) override;
    void onUpdate(double deltaTime) override;

private:
    Snake& _snake;
    std::shared_ptr<Behavior> _paralyzedObject;
    int _paralyzedDuration{0};

    float PUSH_FORCE{100000};
    int PARALYZE_DURATION{100};
};


#endif //GOAT_ENGINE_SNAKESCRIPT_HPP
