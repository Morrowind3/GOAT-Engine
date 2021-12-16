#ifndef GOAT_ENGINE_OBJECT_SCOREBOARDSPECIFICETAPPEBUTTON_HPP
#define GOAT_ENGINE_OBJECT_SCOREBOARDSPECIFICETAPPEBUTTON_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_ScoreboardSpecificEtappeButton: public GameObject {
    public: Object_ScoreboardSpecificEtappeButton(unsigned short etappeNumber, Text& scoreboardHeader, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_SCOREBOARDSPECIFICETAPPEBUTTON_HPP
