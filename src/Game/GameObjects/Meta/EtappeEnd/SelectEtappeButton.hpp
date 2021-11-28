//
// Created by Morrowind3 on 28/11/2021.
//

#ifndef GOAT_ENGINE_SELECTETAPPEBUTTON_HPP
#define GOAT_ENGINE_SELECTETAPPEBUTTON_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/SceneManager.hpp"

using namespace Engine;


class SelectEtappeButton : public GameObject {
public:  SelectEtappeButton(SceneManager& sceneManager, Transform transform, bool active);
};


#endif //GOAT_ENGINE_SELECTETAPPEBUTTON_HPP
