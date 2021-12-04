#include "MountEverestimateLevelConstructor.hpp"
#include "GameObjects/Tiles/SolidTile/SolidTile.hpp"
#include "GameObjects/Tiles/SlabTile/SlabTile.hpp"
#include "GameObjects/Enemies/Goat/Goat.hpp"
#include "GameObjects/WorldObjects/VictoryFlag/VictoryFlag.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "../Engine/Utilities/Globals.hpp"
#include "Keys.hpp"
#include "Layers.hpp"
#include "GameObjects/Tiles/LavaTile/LavaTile.hpp"
#include "GameObjects/WorldObjects/HealthPickup/HealthPickup.hpp"
#include "GameObjects/Enemies/Snake/Snake.hpp"

#include <regex>
#include <fstream>

MountEverestimateLevelConstructor::MountEverestimateLevelConstructor(SharedEtappe& etappe, const std::string& fileLocation,
                                                                     int tileSize, int columns, int rows, int scale):
        _etappe{etappe}, _fileLocation{fileLocation}, _tileSize{tileSize}, _columns{columns}, _rows{rows}, _scale{(double)scale} {
}

void MountEverestimateLevelConstructor::construct(int xOffset, int yOffset) { try {
        // Step 1: Read and clean input
        // Get file as string
        std::ifstream file(_fileLocation);
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string text = buffer.str();


        // Remove all '\n' from string
        std::string toErase{"\n"};
        while (size_t removePosition = text.find(toErase) != std::string::npos) {
            text.erase(removePosition, toErase.length());
        }

        // Split on ',' or ', '
        std::regex reg("[,|, ]");
        std::sregex_token_iterator first{text.begin(), text.end(), reg,
                                         -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
        std::vector<std::string> messyIndexes{first, last};

        // Remove empty indexes
        std::vector<std::string> indexes;
        std::copy_if(messyIndexes.begin(), messyIndexes.end(), std::back_inserter(indexes),
                     [](const std::string& i) { return !i.empty(); });

        // Step 2: Construct level from cleaned input
        // Loop through indexes
        size_t counter {0};
        for (int y = 0; y < _columns; y++) {
            for (int x = 0; x < _rows; x++) {
                int index{std::stoi(indexes.at(counter++))};

                // Skip if index = 0 (empty tile)
                if (index != 0) {
                    double posY{y * _tileSize * _scale};
                    double posX{x * _tileSize * _scale};
                    Transform transform{Point{posX+xOffset, posY+yOffset}, LAYER::TILES_FRONT, 0, _scale, _scale};
                    placeTile(index, transform);
                }
            }
        } } catch (...) { throw std::runtime_error("Level " + _fileLocation + " is invalid"); }

    // Debug code to see where all tiles have been constructed
    if (Globals::getInstance().gameExists(Keys::LEVEL_DEBUG)) {
        auto& debug = Debug::getInstance();
        for (auto& tile : _etappe.gameObjects) {
            debug.log(
                    "[SP: " + tile->sprites.at(Keys::SPRITE).path +             // Sprite Path
                    ", SA: " + std::to_string(tile->sprites.at(Keys::SPRITE).active) +  // Sprite Active
                    ", A: " + std::to_string(tile->active) +                            // Active
                    ", X: " + std::to_string(tile->transform.position.x) +              // X
                    ", Y: " + std::to_string(tile->transform.position.y) +              // Y
                    ", L: " + std::to_string(tile->transform.layer) +                   // Layer
                    ", SW: " + std::to_string(tile->transform.scaleWidth) +             // Scale Width
                    ", SH: " + std::to_string(tile->transform.scaleHeight) +            // Scale Height
                    "]");
        }
    }
}

void MountEverestimateLevelConstructor::placeTile(int index, Transform transform) {

    //NOTE index corresponts with tileset All_Tiles ID's + 1, so '0' in tileset = '1' as index
    //NOTE NEVER REMOVE TILES FROM TILESET
    //NOTE however, you can always add new tiles
    //NOTE every etappe needs a player (edmund sprite)!

    switch (index) {
        // TILES GRASS
        case 1:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/grass/grass_slab_flat.png", transform, true));
            break;
        case 2:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/grass/grass_slab_normal.png", transform, true));
            break;
        case 3:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_empty.png", transform, true));
            break;
        case 4:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_end_left.png", transform, true));
            break;
        case 5:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_end_right.png", transform, true));
            break;
        case 6:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_flat.png", transform, true));
            break;
        case 7:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_normal.png", transform, true));
            break;
        case 8:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/grass/grass_slab_end_left.png", transform, true));
            break;
        case 9:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/grass/grass_slab_end_right.png", transform, true));
            break;
        case 10:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/lava/lava_slab_end_right.png", transform, true));
            break;
        case 11:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/lava/lava_slab_normal.png", transform, true));
            break;
        case 12:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/lava/lava_ground_empty.png", transform, true));
            break;
        case 13:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/lava/lava_ground_end_left.png", transform, true));
            break;
        case 14:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/lava/lava_ground_end_right.png", transform, true));
            break;
        case 15:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/lava/lava_ground_flat.png", transform, true));
            break;
        case 16:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/lava/lava_ground_normal.png", transform, true));
            break;
        case 17:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/lava/lava_slab_end_left.png", transform, true));
            break;
        case 18:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/lava/lava_slab_end_right.png", transform, true));
            break;
        case 19:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/snow/snow_slab_end_right.png", transform, true));
            break;
        case 20:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/snow/snow_slab_normal.png", transform, true));
            break;
        case 21:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/snow/snow_ground_empty.png", transform, true));
            break;
        case 22:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/snow/snow_ground_end_left.png", transform, true));
            break;
        case 23:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/snow/snow_ground_end_right.png", transform, true));
            break;
        case 24:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/snow/snow_ground_flat.png", transform, true));
            break;
        case 25:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/snow/snow_ground_normal.png", transform, true));
            break;
        case 26:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/snow/snow_slab_end_left.png", transform, true));
            break;
        case 27:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/snow/snow_slab_end_right.png", transform, true));
            break;
        case 28:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/stone/stone_slab_end_right.png", transform, true));
            break;
        case 29:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/stone/stone_slab_normal.png", transform, true));
            break;
        case 30:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/stone/stone_ground_empty.png", transform, true));
            break;
        case 31:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/stone/stone_ground_end_left.png", transform, true));
            break;
        case 32:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/stone/stone_ground_end_right.png", transform, true));
            break;
        case 33:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/stone/stone_ground_flat.png", transform, true));
            break;
        case 34:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/stone/stone_ground_normal.png", transform, true));
            break;
        case 35:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/stone/stone_slab_end_left.png", transform, true));
            break;
        case 36:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/stone/stone_slab_end_right.png", transform, true));
            break;
        case 37:
            //TODO hawk GameObject
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/enemies/bird/bird_idle_2.png", transform, true));
            break;
        case 45:
            _etappe.gameObjects.emplace_back(std::make_shared<Goat>(transform, true));
            break;
        case 46:
            _etappe.gameObjects.emplace_back(std::make_shared<Snake>(transform, true));
            break;
        case 47:
            //TODO snowball GameObject
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/enemies/snowball/snowball.png", transform, true));
            break;
        case 48:
            _etappe.gameObjects.emplace_back(std::make_shared<VictoryFlag>(transform, true));
            break;
        case 49:
            transform.rotation = transform.rotation - 45;
            _etappe.gameObjects.emplace_back(std::make_shared<HealthPickup>(transform, true));
            break;
        case 50:
            _etappe.gameObjects.emplace_back(std::make_shared<LavaTile>(transform, true));
            break;
        case 51:
            //TODO iceTile GameObject
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/utils/lakes/lake_ice.png", transform, true));
            break;
        case 52:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_leaves_side_right_2.png", transform, true));
            break;
        case 53:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_leaves_top_1.png", transform, true));
            break;
        case 54:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_leaves_top_2.png", transform, true));
            break;
        case 55:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_middle_branch_left.png", transform, true));
            break;
        case 56:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_middle_branch_right.png", transform, true));
            break;
        case 57:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_middle_normal.png", transform, true));
            break;
        case 58:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_sapling.png", transform, true));
            break;
        case 59:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_stump_bottom.png", transform, true));
            break;
        case 60:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_stump_top.png", transform, true));
            break;
        case 61:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_branch.png", transform, true));
            break;
        case 62:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_branch_left.png", transform, true));
            break;
        case 63:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_branch_right.png", transform, true));
            break;
        case 64:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_leaves_middle.png", transform, true));
            break;
        case 65:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_leaves_side_left_1.png", transform, true));
            break;
        case 66:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_leaves_side_left_2.png", transform, true));
            break;
        case 67:
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/utils/tree/tree_leaves_side_right_1.png", transform, true));
            break;
        case 68:
            //TODO Trash GameObject die een random afval sprite pakt
            _etappe.gameObjects.emplace_back(std::make_shared<Tile>(
                    "Sprites/waste/waste_pizzabox.png", transform, true));
            break;
        case 69:
            transform.layer = LAYER::CHARACTER;
            transform.scaleWidth = 5;
            transform.scaleHeight = 5;
            _etappe.player = std::make_shared<Player>(transform, true);
            _etappe.gameObjects.emplace_back(_etappe.player);
            break;
        default:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/tile_not_found.png", transform, true));
            break;
    }
}
