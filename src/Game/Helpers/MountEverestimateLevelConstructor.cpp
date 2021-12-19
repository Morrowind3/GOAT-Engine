#include "MountEverestimateLevelConstructor.hpp"
#include "../GameObjects/Tiles/SolidTile/Object_SolidTile.hpp"
#include "../GameObjects/Tiles/SlabTile/Object_SlabTile.hpp"
#include "../GameObjects/Enemies/Goat/Object_Goat.hpp"
#include "../GameObjects/WorldObjects/VictoryFlag/Object_VictoryFlag.hpp"
#include "../../Engine/Utilities/Debug.hpp"
#include "../../Engine/Utilities/Globals.hpp"
#include "../Keys.hpp"
#include "../Layers.hpp"
#include "../GameObjects/Tiles/LavaTile/Object_LavaTile.hpp"
#include "../GameObjects/WorldObjects/HealthPickup/Object_HealthPickup.hpp"
#include "../GameObjects/Enemies/Snake/Object_Snake.hpp"
#include "../GameObjects/Enemies/Snowball/Object_Snowball.hpp"
#include "../GameObjects/WorldObjects/Trash/Object_Trash.hpp"
#include "../GameObjects/Tiles/WallTile/Object_WallTile.hpp"
#include "../GameObjects/Enemies/Hawk/Object_Hawk.hpp"
#include "../GameObjects/Utils/Decor/Object_Cloud.hpp"
#include "../GameObjects/Utils/Decor/Advertising/Object_Aeroplane.hpp"
#include "../GameObjects/Utils/Decor/Advertising/Object_Banner.hpp"
#include "../GameObjects/Utils/Decor/Advertising/Object_AdvertisingPane.hpp"
#include "../GameObjects/Tiles/SolidTile/Object_EmptySolidTile.hpp"
#include "../GameObjects/Tiles/IceTile/Object_IceTile.hpp"

#include <regex>
#include <fstream>

MountEverestimateLevelConstructor::MountEverestimateLevelConstructor(SceneTemplate_Etappe& etappe,
                                                                     const std::string& fileLocation,
                                                                     int tileSize, int columns, int rows, int scale) :
        _etappe{etappe}, _fileLocation{fileLocation}, _tileSize{tileSize}, _columns{columns}, _rows{rows},
        _scale{(double) scale} {
}

void MountEverestimateLevelConstructor::construct(int xOffset, int yOffset) {
    try {
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
        this->loadTiles(xOffset, yOffset, indexes);
        this->loadPlayer(xOffset, yOffset, indexes);
        this->loadEnemies(xOffset, yOffset, indexes);
    } catch (...) { throw std::runtime_error("Level " + _fileLocation + " is invalid"); }

    // Debug code to see where all tiles have been constructed
    if (_globals.gameExists(Keys::LEVEL_DEBUG)) {
        for (auto& tile: _etappe.gameObjects) {
            _debug.log(
                    "[SP: " + tile->sprites.at(Keys::SPRITE).path +                     // Sprite Path
                    ", SA: " + std::to_string(tile->sprites.at(Keys::SPRITE).active) +  // Sprite Active
                    ", A: " + std::to_string(tile->active) +                            // Active
                    ", X: " + std::to_string(tile->transform.position.x) +              // X
                    ", Y: " + std::to_string(tile->transform.position.y) +              // Y
                    ", LG: " + std::to_string(tile->transform.layerGroup) +             // Layer group
                    ", LIG: " + std::to_string(tile->transform.layerInsideGroup) +      // Layer inside group
                    ", SW: " + std::to_string(tile->transform.scaleWidth) +             // Scale Width
                    ", SH: " + std::to_string(tile->transform.scaleHeight) +            // Scale Height
                    "]");
        }
    }
}

//NOTE index corresponds with tileset All_Tiles ID's + 1, so '0' in tileset = '1' as index
//NOTE NEVER REMOVE TILES FROM TILESET
//NOTE however, you can always add new tiles
//NOTE every etappe needs a player (edmund sprite)!


void MountEverestimateLevelConstructor::loadTiles(int xOffset, int yOffset, std::vector<std::string> indexes) {
    _debug.log("Constructing tiles");
    size_t counter{0};
    for (int y = 0; y < _columns; y++) {
        for (int x = 0; x < _rows; x++) {
            int index{std::stoi(indexes.at(counter++))};

            // Skip if index = 0 (empty tile)
            if (index != 0) {
                double posY{y * _tileSize * _scale};
                double posX{x * _tileSize * _scale};
                Transform transform{Point{posX + xOffset, posY + yOffset}, LAYER::TILES_FRONT, 0, 0, _scale, _scale};
                switch (index) {
                    case 1:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/grass/grass_slab_flat.png", transform, true));
                        break;
                    case 2:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/grass/grass_slab_normal.png", transform, true));
                        break;
                    case 3:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_WallTile>(
                                "Sprites/landscapes/grass/grass_ground_empty.png", transform, true));
                        break;
                    case 4:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/grass/grass_ground_end_left.png", transform, true));
                        break;
                    case 5:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/grass/grass_ground_end_right.png", transform, true));
                        break;
                    case 6:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/grass/grass_ground_flat.png", transform, true));
                        break;
                    case 7:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/grass/grass_ground_normal.png", transform, true));
                        break;
                    case 8:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/grass/grass_slab_end_left.png", transform, true));
                        break;
                    case 9:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/grass/grass_slab_end_right.png", transform, true));
                        break;
                    case 10:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/lava/lava_slab_end_right.png", transform, true));
                        break;
                    case 11:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/lava/lava_slab_normal.png", transform, true));
                        break;
                    case 12:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_WallTile>(
                                "Sprites/landscapes/lava/lava_ground_empty.png", transform, true));
                        break;
                    case 13:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/lava/lava_ground_end_left.png", transform, true));
                        break;
                    case 14:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/lava/lava_ground_end_right.png", transform, true));
                        break;
                    case 15:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/lava/lava_ground_flat.png", transform, true));
                        break;
                    case 16:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/lava/lava_ground_normal.png", transform, true));
                        break;
                    case 17:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/lava/lava_slab_end_left.png", transform, true));
                        break;
                    case 18:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/lava/lava_slab_end_right.png", transform, true));
                        break;
                    case 19:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/snow/snow_slab_end_right.png", transform, true));
                        break;
                    case 20:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/snow/snow_slab_normal.png", transform, true));
                        break;
                    case 21:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_WallTile>(
                                "Sprites/landscapes/snow/snow_ground_empty.png", transform, true));
                        break;
                    case 22:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/snow/snow_ground_end_left.png", transform, true));
                        break;
                    case 23:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/snow/snow_ground_end_right.png", transform, true));
                        break;
                    case 24:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/snow/snow_ground_flat.png", transform, true));
                        break;
                    case 25:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/snow/snow_ground_normal.png", transform, true));
                        break;
                    case 26:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/snow/snow_slab_end_left.png", transform, true));
                        break;
                    case 27:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/snow/snow_slab_end_right.png", transform, true));
                        break;
                    case 28:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/stone/stone_slab_flat.png", transform, true));
                        break;
                    case 29:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/stone/stone_slab_normal.png", transform, true));
                        break;
                    case 30:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_WallTile>(
                                "Sprites/landscapes/stone/stone_ground_empty.png", transform, true));
                        break;
                    case 31:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/stone/stone_ground_end_left.png", transform, true));
                        break;
                    case 32:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/stone/stone_ground_end_right.png", transform, true));
                        break;
                    case 33:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/stone/stone_ground_flat.png", transform, true));
                        break;
                    case 34:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SolidTile>(
                                "Sprites/landscapes/stone/stone_ground_normal.png", transform, true));
                        break;
                    case 35:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/stone/stone_slab_end_left.png", transform, true));
                        break;
                    case 36:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_SlabTile>(
                                "Sprites/landscapes/stone/stone_slab_end_right.png", transform, true));
                        break;
                    case 51:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_EmptySolidTile>(
                                "Sprites/utils/lakes/lake_ice.png", transform, true));
                        break;
                    case 52:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_leaves_side_right_2.png", transform, true));
                        break;
                    case 53:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_leaves_top_1.png", transform, true));
                        break;
                    case 54:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_leaves_top_2.png", transform, true));
                        break;
                    case 55:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_middle_branch_left.png", transform, true));
                        break;
                    case 56:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_middle_branch_right.png", transform, true));
                        break;
                    case 57:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_middle_normal.png", transform, true));
                        break;
                    case 58:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_sapling.png", transform, true));
                        break;
                    case 59:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_stump_bottom.png", transform, true));
                        break;
                    case 60:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_stump_top.png", transform, true));
                        break;
                    case 61:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_branch.png", transform, true));
                        break;
                    case 62:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_branch_left.png", transform, true));
                        break;
                    case 63:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_branch_right.png", transform, true));
                        break;
                    case 64:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_leaves_middle.png", transform, true));
                        break;
                    case 65:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_leaves_side_left_1.png", transform, true));
                        break;
                    case 66:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_leaves_side_left_2.png", transform, true));
                        break;
                    case 67:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Tile>(
                                "Sprites/utils/tree/tree_leaves_side_right_1.png", transform, true));
                        break;
                    case 79:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_EmptySolidTile>(
                                "Sprites/landscapes/grass/grass_ground_empty.png", transform, true));
                        break;
                    case 80:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_EmptySolidTile>(
                                "Sprites/landscapes/stone/stone_ground_empty.png", transform, true));
                        break;
                    case 81:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_EmptySolidTile>(
                                "Sprites/landscapes/snow/snow_ground_empty.png", transform, true));
                        break;
                    case 82:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_EmptySolidTile>(
                                "Sprites/landscapes/lava/lava_ground_empty.png", transform, true));
                        break;
                    case 83:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_IceTile>(
                                "Sprites/utils/lakes/lake_ice_top.png", transform, true));
                    default:
                        break;
                }
            }
        }
    }
}

void MountEverestimateLevelConstructor::loadPlayer(int xOffset, int yOffset, std::vector<std::string> indexes) {
    _debug.log("Constructing player");
    size_t counter{0};
    for (int y = 0; y < _columns; y++) {
        for (int x = 0; x < _rows; x++) {
            int index{std::stoi(indexes.at(counter++))};
            if (index == 69) {
                double posY{y * _tileSize * _scale};
                double posX{x * _tileSize * _scale};
                Transform transform{Point{posX + xOffset, posY + yOffset}, LAYER::TILES_FRONT, 0, 0, _scale, _scale};
                transform.layerGroup = LAYER::CHARACTER;
                transform.scaleWidth = 5;
                transform.scaleHeight = 5;
                _etappe.player = std::make_shared<Object_Player>(transform, true);
                _etappe.gameObjects.emplace_back(_etappe.player);
                return;
            }
        }
    }
}

void MountEverestimateLevelConstructor::loadEnemies(int xOffset, int yOffset, std::vector<std::string> indexes) {
    _debug.log("Constructing enemies");

    std::shared_ptr<Object_Aeroplane> plane;
    std::shared_ptr<Object_Banner> banner;
    std::shared_ptr<Object_AdvertisingPane> bannerAdvert;

    size_t counter{0};
    for (int y = 0; y < _columns; y++) {
        for (int x = 0; x < _rows; x++) {
            int index{std::stoi(indexes.at(counter++))};

            // Skip if index = 0 (empty tile)
            if (index != 0) {
                double posY{y * _tileSize * _scale};
                double posX{x * _tileSize * _scale};
                Transform transform{Point{posX + xOffset, posY + yOffset}, LAYER::TILES_FRONT, 0, 0, _scale, _scale};
                switch (index) {
                    case 37:
                        _etappe.gameObjects.emplace_back(
                                std::make_shared<Object_Hawk>(*_etappe.player, transform, true));
                        break;
                    case 45:
                        _etappe.gameObjects.emplace_back(
                                std::make_shared<Object_Goat>(*_etappe.player, transform, true));
                        break;
                    case 46:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Snake>(transform, true));
                        break;
                    case 47:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Snowball>(transform, true));
                        break;
                    case 48:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_VictoryFlag>(transform, true));
                        break;
                    case 49:
                        transform.rotation = transform.rotation - 45;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_HealthPickup>(transform, true));
                        break;
                    case 50:
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_LavaTile>(transform, true));
                        break;
                    case 68:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(std::make_shared<Object_Trash>(transform, true));
                        break;
                    case 74:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(
                                std::make_shared<Object_Cloud>(Object_Cloud::CloudShape::BIG, transform, true));
                        break;
                    case 75:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(
                                std::make_shared<Object_Cloud>(Object_Cloud::CloudShape::SMALL, transform, true));
                        break;
                    case 76:
                        transform.layerGroup = LAYER::TILES_BACK;
                        _etappe.gameObjects.emplace_back(
                                std::make_shared<Object_Cloud>(Object_Cloud::CloudShape::WIDE, transform, true));
                        break;
                    case 77:
                        banner = std::make_shared<Object_Banner>(transform, true);
                        bannerAdvert = std::make_shared<Object_AdvertisingPane>(transform, true);
                        banner->transform.layerGroup = LAYER::TILES_BACK;
                        plane = std::make_shared<Object_Aeroplane>(transform, 3000, true);
                        _etappe.gameObjects.emplace_back(plane);
                        banner->transform.position.x = banner->transform.position.x + 240;
                        banner->transform.position.y = banner->transform.position.y - 25;
                        _etappe.gameObjects.emplace_back(banner);
                        bannerAdvert->transform = banner->transform;
                        //User-defined image, so force dimensions
                        bannerAdvert->transform.forcedWidth = 250;
                        bannerAdvert->transform.forcedHeight = 130;
                        bannerAdvert->transform.position.y = bannerAdvert->transform.position.y + 40;
                        bannerAdvert->transform.position.x = bannerAdvert->transform.position.x + 32;
                        bannerAdvert->transform.layerGroup = LAYER::TILES_BACK + 1;
                        _etappe.gameObjects.emplace_back(bannerAdvert);
                        plane->followPlaneMovement(bannerAdvert);
                        plane->followPlaneMovement(banner);
                        break;
                }
            }
        }
    }
}