//
// Created by Morrowind3 on 28/11/2021.
//

#ifndef GOAT_ENGINE_NEXTETAPPEBUTTON_HPP
#define GOAT_ENGINE_NEXTETAPPEBUTTON_HPP

#include "../../../../Engine/SceneManager.hpp"

using namespace Engine;

class NextEtappeButton : public GameObject {
public:  NextEtappeButton(SceneManager& sceneManager, Transform transform, bool active);
};


#endif //GOAT_ENGINE_NEXTETAPPEBUTTON_HPP
