#include "TiledMap.hpp"

using namespace Engine;

TiledMap::TiledMap(std::string path, int tilesX, int tilesY, int tileSize, std::map<int, std::string> tileDictionary,
                   bool active) :
        GameComponent(active), path(std::move(path)), tilesX(tilesX), tilesY(tilesY), tileSize(tileSize),
        tileDictionary(std::move(tileDictionary)) {}