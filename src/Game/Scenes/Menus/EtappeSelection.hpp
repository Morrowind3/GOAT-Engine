#ifndef GOAT_ENGINE_ETAPPESELECTION_HPP
#define GOAT_ENGINE_ETAPPESELECTION_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_StaticScreen.hpp"

using namespace Engine;

class EtappeSelection : public SceneTemplate_StaticScreen {
    public: explicit EtappeSelection(SceneManager& manager);
};

#endif //GOAT_ENGINE_ETAPPESELECTION_HPP
