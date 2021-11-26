#include "SharedEtappe.hpp"
#include "../../GameObjects/Meta/Hud/FpsDisplay.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Meta/Hud/LifeHeart.hpp"

SharedEtappe::SharedEtappe(const std::string& etappeKey, Transform playerStartPosition): Scene(etappeKey) {
    // Hud
    gameObjects.emplace_back(std::make_shared<FpsDisplay>(true));
    // Hearts (hud)
    gameObjects.emplace_back(std::make_shared<LifeHeart>(1,
        Transform{{0,0},LAYER::UI,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<LifeHeart>(2,
        Transform{{105,0},LAYER::UI,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<LifeHeart>(3,
        Transform{{210,0},LAYER::UI,0,5,5},true));
    _player = std::make_shared<Player>(playerStartPosition,true);
    gameObjects.emplace_back(_player);
}
