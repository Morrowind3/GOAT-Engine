#include "MountEverestimateLevelConstructor.hpp"
#include "GameObjects/Tiles/SolidTile.hpp"
#include "GameObjects/Tiles/SlabTile.hpp"
#include "GameObjects/Enemies/Goat.hpp"
#include "GameObjects/WorldObjects/VictoryFlag.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "../Engine/Utilities/Globals.hpp"
#include "Keys.hpp"
#include "Layers.hpp"
#include "GameObjects/Tiles/LavaTile.hpp"

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
    std::string texturePath;
    switch (index) {
        // TILES GRASS
        case 1:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_empty.png", transform, true));
            break;
        case 2:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_end_left.png", transform, true));
            break;
        case 3:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_end_right.png", transform, true));
            break;
        case 4:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_flat.png", transform, true));
            break;
        case 5:
            _etappe.gameObjects.emplace_back(std::make_shared<SolidTile>(
                    "Sprites/landscapes/grass/grass_ground_normal.png", transform, true));
            break;
        case 6:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile >(
                    "Sprites/landscapes/grass/grass_slab_end_left.png", transform, true));
            break;
        case 7:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/grass/grass_slab_end_right.png", transform, true));
            break;
        case 8:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/grass/grass_slab_flat.png", transform, true));
            break;
        case 9:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<SlabTile>(
                    "Sprites/landscapes/grass/grass_slab_normal.png", transform, true));
            break;
        case 12:
            _etappe.gameObjects.emplace_back(std::make_shared<LavaTile>(transform, true));
            break;
        case 14:
            _etappe.gameObjects.emplace_back(std::make_shared<Goat>(transform, true));
            break;
        case 19:
            //TODO Hawk
            break;
        case 23:
            //TODO Snake
            break;
        case 24:
            //TODO Snowball
            break;
        //TODO lava/stone/snow tiles
        case 10:
            transform.layer = LAYER::TILES_BACK;
            _etappe.gameObjects.emplace_back(std::make_shared<VictoryFlag>(transform, true));
            break;
        default:
            break;
    }
}
