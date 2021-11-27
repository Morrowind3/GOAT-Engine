#include "SharedEtappe.hpp"
#include "../../GameObjects/Meta/Hud/FpsDisplay.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Meta/Hud/LifeHeart.hpp"
#include "../../MountEverestimateLevelConstructor.hpp"
#include "../../GameObjects/Meta/Cheats.hpp"

SharedEtappe::SharedEtappe(const std::string& etappeKey, Transform playerStartPosition,
    const std::string& fileLocation, int tileSize, int columns, int rows, int scale, int xOffset, int yOffset): Scene(etappeKey) {
    // Level
    MountEverestimateLevelConstructor{*this, fileLocation, tileSize, columns, rows, scale}.Construct(xOffset, yOffset);

    // Cheats
    gameObjects.emplace_back(std::make_shared<Cheats>(true));

    // Hud
    gameObjects.emplace_back(std::make_shared<FpsDisplay>(true));
    // Hearts (hud)
    gameObjects.emplace_back(std::make_shared<LifeHeart>(1,
        Transform{{0,0},LAYER::UI,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<LifeHeart>(2,
        Transform{{105,0},LAYER::UI,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<LifeHeart>(3,
        Transform{{210,0},LAYER::UI,0,5,5},true));

    gameObjects.emplace_back(std::make_shared<Player>(playerStartPosition,true));
}
