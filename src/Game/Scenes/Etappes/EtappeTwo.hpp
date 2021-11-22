//
// Created by Stijn van Loon on 19-11-2021.
//

#ifndef GOAT_ENGINE_ETAPPETWO_HPP
#define GOAT_ENGINE_ETAPPETWO_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Meta/EtappeTwoManager.hpp"
#include "../../GameObjects/Tiles/SolidTile.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <regex>

using namespace Engine;

class EtappeTwo : public Scene {
public:
    EtappeTwo() : Scene("Etappe two") {

        int tileSize{21};
        int tilesY{50};
        int tilesX{250};
        double scale{1};

        // get file as string
        std::ifstream file("Maps/etappe2.map");
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string text = buffer.str();

        // remove all '\n' from string
        std::string toErase {"\n"};
        while (true) {
            size_t removePos = text.find(toErase);
            if(removePos != std::string::npos) text.erase(removePos, toErase.length());
            else break;
        }

        // split on ',' or ', '
        std::regex re("[,|, ]");
        std::sregex_token_iterator first{text.begin(), text.end(), re, -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
        std::vector<std::string> messyIndexes{first, last};

        // remove empty indexes
        std::vector<std::string> indexes;
        std::copy_if (messyIndexes.begin(), messyIndexes.end(), std::back_inserter(indexes), [](const std::string& i){return i.size() > 0;} );

        // loop through indexes
        size_t counter{0};

        for (int y = 0; y < tilesY; y++)
        {
            for (int x = 0; x < tilesX; x++) {

                //skip if index = 0
                if(std::stoi(indexes.at(counter)) != 0) {
                    double posY {y * tileSize * scale};
                    double posX {x * tileSize * scale};

                    gameObjects.emplace_back(new SolidTile{
                            getSprite(std::stoi(indexes.at(counter))),
                            Transform{Point{posX, posY}, 10, 0, scale, scale},
                            true });
                }
                counter++;
            }
        }
    }

    std::string getSprite(int index) {
        switch (index) {
            case 1: return "Sprites/landscapes/grass/grass_ground_empty.png";
            case 2: return "Sprites/landscapes/grass/grass_ground_end_left.png";
            case 3: return "Sprites/landscapes/grass/grass_ground_end_right.png";
            case 4: return "Sprites/landscapes/grass/grass_ground_flat.png";
            case 5: return "Sprites/landscapes/grass/grass_ground_normal.png";
            case 6: return "Sprites/landscapes/grass/grass_slab_end_left.png";
            case 7: return "Sprites/landscapes/grass/grass_slab_end_right.png";
            case 8: return "Sprites/landscapes/grass/grass_slab_flat.png";
            case 9: return "Sprites/landscapes/grass/grass_slab_normal.png";
            case 10: return "Sprites/landscapes/stone/stone_ground_empty.png";
            case 11: return "Sprites/landscapes/stone/stone_ground_end_left.png";
            case 12: return "Sprites/landscapes/stone/stone_ground_end_right.png";
            case 13: return "Sprites/landscapes/stone/stone_ground_flat.png";
            case 14: return "Sprites/landscapes/stone/stone_ground_normal.png";
            case 15: return "Sprites/landscapes/stone/stone_slab_end_left.png";
            case 16: return "Sprites/landscapes/stone/stone_slab_end_right.png";
            case 17: return "Sprites/landscapes/stone/stone_slab_flat.png";
            case 18: return "Sprites/landscapes/stone/stone_slab_normal.png";

            default: return "";
        }
    }
};

#endif //GOAT_ENGINE_ETAPPETWO_HPP
