#ifndef GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP
#define GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP

#include "../Engine/API/Scene.hpp"
#include "Scenes/Templates/SharedEtappe.hpp"

using namespace Engine;

class MountEverestimateLevelConstructor {
    public:
        MountEverestimateLevelConstructor(SharedEtappe& etappe, const std::string& fileLocation,
                                          int tileSize, int columns, int rows, int scale);
        void construct(int xOffset, int yOffset);
    private:
        SharedEtappe& _etappe;
        const std::string& _fileLocation;
        void placeTile(int index, Transform transform);
        const int _tileSize, _columns, _rows;
        const double _scale; // Essentially an int, but needs to be a double for proper calculations
};


#endif //GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP
