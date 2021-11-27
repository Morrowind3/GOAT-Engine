#include "SharedEtappe.hpp"
#include "../../GameObjects/Meta/Hud/FpsDisplay.hpp"
#include "../../GameObjects/Meta/Hud/LifeHeart.hpp"
#include "../../../Engine/Utilities/Globals.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Meta/GameStateManager.hpp"

SharedEtappe::SharedEtappe(const std::string& etappeKey, Transform playerStartPosition, SceneManager& sceneManager): Scene(etappeKey), _sceneManager(sceneManager) {
    gameObjects.emplace_back(std::make_shared<GameStateManager>(sceneManager, true));
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
    _camera.TrackObject(_player);


    Globals::GetInstance().gameStore(Keys::GAMESTATE, Keys::GAMESTATE_DEFAULT);
}
