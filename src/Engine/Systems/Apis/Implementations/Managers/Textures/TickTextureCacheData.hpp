#ifndef GOAT_ENGINE_TICKTEXTURECACHEDATA_HPP
#define GOAT_ENGINE_TICKTEXTURECACHEDATA_HPP

#include "../../../../../API/GameObjects/Transform.hpp"
#include "Texture.hpp"

using namespace Engine;

// Needed to properly order the tick texture cache
class TickTextureCacheData {
    public:
    explicit TickTextureCacheData(Transform transform, const Texture* data);
    unsigned long long sortingKey; // Concatenation of layer group and layer inside group
    // Data
    Transform transform;
    const Texture* data;
    // Required to sort
    TickTextureCacheData& operator=(const TickTextureCacheData& other);
    bool operator==(const TickTextureCacheData &other) const;
    bool operator!=(const TickTextureCacheData &other) const;
    bool operator<(const TickTextureCacheData &other) const;
    bool operator>(const TickTextureCacheData &other) const;
    bool operator<=(const TickTextureCacheData &other) const;
    bool operator>=(const TickTextureCacheData &other) const;
};

#endif //GOAT_ENGINE_TICKTEXTURECACHEDATA_HPP
