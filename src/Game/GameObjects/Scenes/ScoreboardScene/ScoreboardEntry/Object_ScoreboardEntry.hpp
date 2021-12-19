#ifndef GOAT_ENGINE_OBJECT_SCOREBOARDENTRY_HPP
#define GOAT_ENGINE_OBJECT_SCOREBOARDENTRY_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_ScoreboardEntry: public GameObject {
    public: Object_ScoreboardEntry(unsigned int saveNumber, unsigned int score, bool isWinner, const Transform& transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_SCOREBOARDENTRY_HPP
