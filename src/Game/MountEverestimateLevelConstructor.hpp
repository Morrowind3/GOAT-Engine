#ifndef GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP
#define GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP

#include "../Engine/API/Scene.hpp"
#include "Scenes/Templates/SceneTemplate_Etappe.hpp"
#include "../Engine/Utilities/Globals.hpp"
#include "../Engine/Utilities/Debug.hpp"

using namespace Engine;

class MountEverestimateLevelConstructor {
    public:
        MountEverestimateLevelConstructor(SceneTemplate_Etappe& etappe, const std::string& fileLocation,
                                          int tileSize, int columns, int rows, int scale);
        void construct(int xOffset, int yOffset);
    private:
        Debug& _debug = Debug::getInstance();
        Globals& _globals = Globals::getInstance();
        SceneTemplate_Etappe& _etappe;
        const std::string& _fileLocation;
        const int _tileSize, _columns, _rows;
        const double _scale; // Essentially an int, but needs to be a double for proper calculations

        void loadTiles(int xOffset, int yOffset, std::vector<std::string> indexes);
        void loadPlayer(int xOffset, int yOffset, std::vector<std::string> indexes);
        void loadEnemies(int xOffset, int yOffset, std::vector<std::string> indexes);
};


#endif //GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP
