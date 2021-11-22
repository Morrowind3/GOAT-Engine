#ifndef GOAT_ENGINE_TILEDMAP_HPP
#define GOAT_ENGINE_TILEDMAP_HPP

#include "../GameComponent.hpp"
#include <string>
#include <map>

namespace Engine {
    struct TiledMap : public GameComponent {
        TiledMap(std::string path, int tilesX, int tilesY, int tileSize, std::map<int, std::string> tileDictionary, bool active);

        // path to .map
        std::string path;

        // amount of tiles on y-axis
        int tilesY;

        // amount of tiles on x-axis
        int tilesX;

        // the size of one sprite, e.g. '21' = 21 x 21 pixels
        int tileSize;

        // tileId in map, path to sprite
        std::map<int, std::string> tileDictionary;
    };
}



#endif //GOAT_ENGINE_TILEDMAP_HPP
