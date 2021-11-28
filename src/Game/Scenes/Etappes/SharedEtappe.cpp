#include "SharedEtappe.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Meta/Hud/LifeHeart.hpp"
#include "../../MountEverestimateLevelConstructor.hpp"
#include "../../GameObjects/Meta/Cheats.hpp"
#include "../../../Engine/Utilities/Globals.hpp"
#include "../../Keys.hpp"

SharedEtappe::SharedEtappe(const std::string& etappeKey, Transform playerStartPosition, SceneManager& sceneManager,
    const std::string& fileLocation, int tileSize, int columns, int rows, int scale, int xOffset, int yOffset): Scene(etappeKey), _sceneManager(sceneManager) {
    // Level
    MountEverestimateLevelConstructor{*this, fileLocation, tileSize, columns, rows, scale}.Construct(xOffset, yOffset);

    // Cheats
    gameObjects.emplace_back(std::make_shared<Cheats>(true));

    // Hud
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
