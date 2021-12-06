#ifndef GOAT_ENGINE_ETAPPESELECTION_HPP
#define GOAT_ENGINE_ETAPPESELECTION_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_Menu.hpp"

using namespace Engine;

class EtappeSelection : public SceneTemplate_Menu {
    public: explicit EtappeSelection(SceneManager& manager);
};

#endif //GOAT_ENGINE_ETAPPESELECTION_HPP
