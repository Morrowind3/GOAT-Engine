//
// Created by Morrowind3 on 18/12/2021.
//

#include "Scene_HelpMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/HelpMenuScene/Object_KeyHelpEntry.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/HelpMenuScene/Object_HelpBackground.hpp"
#include "../../GameObjects/Scenes/HelpMenuScene/Object_KeyHelpKey.hpp"
#include "../../GameObjects/Scenes/HelpMenuScene/Object_KeyHelpDescription.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/Object_BackToMenuButton.hpp"

Scene_HelpMenu::Scene_HelpMenu() : SceneTemplate_Menu(Keys::HELP_MENU) {
    gameObjects.emplace_back(std::make_shared<Object_HelpBackground>(Transform{{0,0}, LAYER::TILES_BACK}, true));

    Transform transform{Point{50, 30}, LAYER::UI, 0, 0, 3,3};

    gameObjects.emplace_back(std::make_shared<Object_KeyHelpDescription>("You play as Edmund Hillary on his quest be the first to climb the Mount Everest.", transform, true));
    transform.position.y = transform.position.y + 40;
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpDescription>("To score points, be quick, pick up trash left others left behind, and avoid taking damage.", transform, true));
    transform.position.y = transform.position.y + 40;
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpDescription>("Collect Jagerpleisters to heal. In contrary to trash, these are collected automatically.", transform, true));
    transform.position.y = transform.position.y + 40;
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpDescription>("A red guide line will indicate a good pace at which you will have a shot at the high score.", transform, true));
    transform.position.y = transform.position.y + 100;

    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("W", transform, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("UP", Transform{{transform.position.x + 100, transform.position.y}, LAYER::UI, 0, 0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("SPACE", Transform{{transform.position.x + 200, transform.position.y}, LAYER::UI, 0 , 0, 3, 5}, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpEntry>("Jump. Press twice to double jump.", transform, true));

    transform.position.y = transform.position.y + 100;
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("A", Transform{{transform.position.x, transform.position.y}, LAYER::UI, 0, 0, 3,3 }, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("LEFT", Transform{{transform.position.x + 100, transform.position.y}, LAYER::UI, 0, 0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpEntry>("Move left", transform, true));

    transform.position.y = transform.position.y + 100;
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("S", Transform{{transform.position.x, transform.position.y}, LAYER::UI, 0, 0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("DOWN", Transform{{transform.position.x + 100, transform.position.y}, LAYER::UI, 0, 0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpEntry>( "Collect Trash", transform, true));

    transform.position.y = transform.position.y + 100;
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("D", Transform{{transform.position.x, transform.position.y}, LAYER::UI, 0, 0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpKey>("RIGHT", Transform{{transform.position.x + 100, transform.position.y}, LAYER::UI, 0, 0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<Object_KeyHelpEntry>( "Move right", transform, true));

    transform.position.y = transform.position.y + 300;
    transform.position.x = transform.position.x + 800;
    transform.scaleHeight = 4;
    transform.scaleWidth = 4;
    gameObjects.emplace_back(std::make_shared<Object_BackToMenuButton>(transform, true));
}
