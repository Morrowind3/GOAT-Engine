#ifndef GOAT_ENGINE_SLABTILESCRIPT_HPP
#define GOAT_ENGINE_SLABTILESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Input.hpp"
#include "../../../GameObjects/Tiles/SlabTile.hpp"

using namespace Engine;

class SlabTileScript : public Script {
public:
    SlabTileScript(SlabTile& self, bool active);
    void OnUpdate(double deltaTime);

private:
    SlabTile& _self;
    Input& _input;
};


#endif //GOAT_ENGINE_SLABTILESCRIPT_HPP
