#ifndef GOAT_ENGINE_LAYERS_HPP
#define GOAT_ENGINE_LAYERS_HPP

// Not an "enum class" because these are essentially named integers
enum LAYER {
    PARALLAX_BACKGROUND = 80,
    PARALLAX_SKYDECOR = 85,
    ETAPPE_TEXT = 99,
    TILES_BACK = 140,
    CHARACTER = 150,
    TILES_FRONT = 160,
    TIMER_LINE = 200,
    UI = 0xffffffff
};

#endif //GOAT_ENGINE_LAYERS_HPP
