#ifndef GOAT_ENGINE_LAYERS_HPP
#define GOAT_ENGINE_LAYERS_HPP

// Not an "enum class" because these are essentially named integers
enum LAYER {
    UI = 0xffffffff,
    PARALLAX_BACKGROUND = 80,
    CHARACTER = 150,
    TILES_FRONT = 160,
    TILES_BACK = 140,
    ETAPPE_TEXT = 99
};

#endif //GOAT_ENGINE_LAYERS_HPP
