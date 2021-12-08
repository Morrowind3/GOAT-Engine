#include <string>
#include "TickTextureCacheData.hpp"

TickTextureCacheData::TickTextureCacheData(const Transform transform, const Texture* data): transform{transform}, data{data} {
    std::string concatenated = std::to_string(transform.layerGroup)+std::to_string(transform.layerInsideGroup);
    sortingKey = (unsigned long long)std::stoll(concatenated);
}

TickTextureCacheData& TickTextureCacheData::operator=(const TickTextureCacheData& other) {
    if (this != &other) {
        sortingKey = other.sortingKey;
        transform = other.transform;
        data = other.data;
    }
    return *this;
}

bool TickTextureCacheData::operator==(const TickTextureCacheData& other) const {
    return sortingKey == other.sortingKey;
}

bool TickTextureCacheData::operator!=(const TickTextureCacheData& other) const {
    return sortingKey != other.sortingKey;
}

bool TickTextureCacheData::operator<(const TickTextureCacheData& other) const {
    return sortingKey < other.sortingKey;
}

bool TickTextureCacheData::operator>(const TickTextureCacheData& other) const {
    return sortingKey > other.sortingKey;
}

bool TickTextureCacheData::operator<=(const TickTextureCacheData& other) const {
    return sortingKey <= other.sortingKey;
}

bool TickTextureCacheData::operator>=(const TickTextureCacheData& other) const {
    return sortingKey >= other.sortingKey;
}
