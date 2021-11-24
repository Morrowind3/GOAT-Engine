#ifndef GOAT_ENGINE_FPSDISPLAY_HPP
#define GOAT_ENGINE_FPSDISPLAY_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class FpsDisplay : public GameObject {
    public: explicit FpsDisplay(bool active);
};

#endif //GOAT_ENGINE_FPSDISPLAY_HPP
