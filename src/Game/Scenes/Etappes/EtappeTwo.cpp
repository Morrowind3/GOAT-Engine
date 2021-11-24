#include "EtappeTwo.hpp"

#include "../../GameObjects/Tiles/SolidTile.hpp"
#include "../../Behaviors/SolidTileBehavior.hpp"
#include "../../GameObjects/Tiles/SlabTile.hpp"

#include <fstream>
#include <string>
#include <regex>
#include <any>
#include <sstream>

// TODO: Delegate tiled level-construction to a more logical place than scene construction
void placeTile(int index, Transform transform, Scene& scene);

EtappeTwo::EtappeTwo(SceneManager& manager) : Scene("Etappe two") {
//        gameObjects.emplace_back(new Player{Transform{Point{100,912},15,0,5,5},true});

    int tileSize{21};
    int tilesY{3};
    int tilesX{3};
    // warn: only use whole numbers like 1, 2, 3. With doubles like 1.3 there will be gaps between tiles
    double scale{3};

    // get file as string
    std::ifstream file("Maps/test.map");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string text = buffer.str();

    // remove all '\n' from string
    std::string toErase{"\n"};
    while (true) {
        size_t removePos = text.find(toErase);
        if (removePos != std::string::npos) text.erase(removePos, toErase.length());
        else break;
    }

    // split on ',' or ', '
    std::regex reg("[,|, ]");
    std::sregex_token_iterator first{text.begin(), text.end(), reg,
                                     -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
    std::vector<std::string> messyIndexes{first, last};

    // remove empty indexes
    std::vector<std::string> indexes;
    std::copy_if(messyIndexes.begin(), messyIndexes.end(), std::back_inserter(indexes),
                 [](const std::string& i) { return !i.empty(); });

    // loop through indexes
    size_t counter{0};

    for (int y = 0; y < tilesY; y++) {
        for (int x = 0; x < tilesX; x++) {
            int index{std::stoi(indexes.at(counter))};

            //skip if index = 0
            if (index != 0) {
                double posY{y * tileSize * scale};
                double posX{x * tileSize * scale};
                Transform transform{Point{posX, posY}, 10, 0, scale, scale};
                Scene& ref = *this;
                placeTile(index, transform, ref);
            }
            counter++;
        }
    }
}

void placeTile(int index, Transform transform, Scene& scene) {
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
        scene.gameObjects.emplace_back(std::make_shared<SolidTile>(texturePath, transform, true));
    } else
    if((index >= 6 && index <= 9) || ( index >= 15 && index <= 18)){
        scene.gameObjects.emplace_back(std::make_shared<SlabTile>(texturePath, transform, true));
    }
}
