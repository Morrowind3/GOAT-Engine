#ifndef GOAT_ENGINE_ETAPPEONE_HPP
#define GOAT_ENGINE_ETAPPEONE_HPP

#include "../../Keys.hpp"
#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"
#include "../../GameObjects/Meta/EtappeOneManager.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class EtappeOne : public Scene {
    public: explicit EtappeOne(SceneManager& manager);
};

#endif //GOAT_ENGINE_ETAPPEONE_HPP
