#ifndef GOAT_ENGINE_OBJECT_SCOREBOARDALLETAPPESBUTTON_HPP
#define GOAT_ENGINE_OBJECT_SCOREBOARDALLETAPPESBUTTON_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_ScoreboardAllEtappesButton: public GameObject {
    public: Object_ScoreboardAllEtappesButton(Text& scoreboardHeader, Transform transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_SCOREBOARDALLETAPPESBUTTON_HPP
