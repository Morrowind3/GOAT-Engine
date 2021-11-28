#include "MountEverestimateLevelConstructor.hpp"
#include "GameObjects/Tiles/SolidTile.hpp"
#include "GameObjects/Tiles/SlabTile.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "../Engine/Utilities/Globals.hpp"
#include "Keys.hpp"

#include <regex>
#include <fstream>

MountEverestimateLevelConstructor::MountEverestimateLevelConstructor(Scene& scene, const std::string& fileLocation,
        int tileSize, int columns, int rows, int scale):
    _scene{scene}, _fileLocation{fileLocation}, _tileSize{tileSize}, _columns{columns}, _rows{rows}, _scale{(double)scale} {
}

void MountEverestimateLevelConstructor::Construct(int xOffset, int yOffset) { try {
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
                Transform transform{Point{posX+xOffset, posY+yOffset}, 10, 0, _scale, _scale};
                PlaceTile(index, transform);
            }
        }
    } } catch (...) { throw std::runtime_error("Level " + _fileLocation + " is invalid"); }

    // Debug code to see where all tiles have been constructed
    if (Globals::GetInstance().gameExists(Keys::LEVEL_DEBUG)) {
        auto& debug = Debug::GetInstance();
        for (auto& tile : _scene.gameObjects) {
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

void MountEverestimateLevelConstructor::PlaceTile(int index, Transform transform) {
    std::string texturePath;
    switch (index) {
        case 1:
            texturePath = "Sprites/landscapes/grass/grass_ground_empty.png";
            break;
        case 2:
            texturePath = "Sprites/landscapes/grass/grass_ground_end_left.png";
            break;
        case 3:
            texturePath = "Sprites/landscapes/grass/grass_ground_end_right.png";
            break;
        case 4:
            texturePath = "Sprites/landscapes/grass/grass_ground_flat.png";
            break;
        case 5:
            texturePath = "Sprites/landscapes/grass/grass_ground_normal.png";
            break;
        case 6:
            texturePath = "Sprites/landscapes/grass/grass_slab_end_left.png";
            break;
        case 7:
            texturePath = "Sprites/landscapes/grass/grass_slab_end_right.png";
            break;
        case 8:
            texturePath = "Sprites/landscapes/grass/grass_slab_flat.png";
            break;
        case 9:
            texturePath = "Sprites/landscapes/grass/grass_slab_normal.png";
            break;
        case 10:
            texturePath = "Sprites/landscapes/grass/stone_ground_empty.png";
            break;
        case 11:
            texturePath = "Sprites/landscapes/grass/stone_ground_end_left.png";
            break;
        case 12:
            texturePath = "Sprites/landscapes/grass/stone_ground_end_right.png";
            break;
        case 13:
            texturePath = "Sprites/landscapes/grass/stone_ground_flat.png";
            break;
        case 14:
            texturePath = "Sprites/landscapes/grass/stone_ground_normal.png";
            break;
        case 15:
            texturePath = "Sprites/landscapes/grass/stone_slab_end_left.png";
            break;
        case 16:
            texturePath = "Sprites/landscapes/grass/stone_slab_end_right.png";
            break;
        case 17:
            texturePath = "Sprites/landscapes/grass/stone_slab_flat.png";
            break;
        case 18:
            texturePath = "Sprites/landscapes/grass/stone_slab_normal.png";
            break;
        default:
            break;
    }
    if(index <= 5 || ( index >= 10 && index <= 14)){
        _scene.gameObjects.emplace_back(std::make_shared<SolidTile>(texturePath, transform, true));
    }
    if((index >= 6 && index <= 9) || ( index >= 15 && index <= 18)){
        _scene.gameObjects.emplace_back(std::make_shared<SlabTile>(texturePath, transform, true));
    }
}
