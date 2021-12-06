#ifndef GOAT_ENGINE_LAYERS_HPP
#define GOAT_ENGINE_LAYERS_HPP

// TODO: Replace this with layer groups and eliminate this
// Not an "enum class" because these are essentially named integers
enum LAYER {
    // Layers < 100 have parallax effect, the lower, the less parralax speed
    FPS = 0xffffffff,
    UI = 200,
    PARALLAX_BACKGROUND = 80,
    CHARACTER = 150,
    TILES_FRONT = 160,
    TILES_BACK = 140,
    ETAPPE_TEXT = 99
};

#endif //GOAT_ENGINE_LAYERS_HPP
