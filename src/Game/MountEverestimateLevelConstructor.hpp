#ifndef GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP
#define GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP

#include "../Engine/API/Scene.hpp"

using namespace Engine;

class MountEverestimateLevelConstructor {
    public:
        MountEverestimateLevelConstructor(Scene& scene, const std::string& fileLocation,
                                          int tileSize, int columns, int rows, int scale);
        void Construct(int xOffset, int yOffset);
    private:
        Scene& _scene;
        const std::string& _fileLocation;
        void PlaceTile(int index, Transform transform);
        const int _tileSize, _columns, _rows;
        const double _scale; // Essentially an int, but needs to be a double for proper calculations
};


#endif //GOAT_ENGINE_MOUNTEVERESTIMATELEVELCONSTRUCTOR_HPP
