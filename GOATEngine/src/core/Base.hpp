#ifndef GOATENGINE_BASE_HPP
#define GOATENGINE_BASE_HPP

#include <memory>
#include <functional>
#include <utility>
#include <cstring>

namespace Engine {
    using int8 = std::int8_t;
    using int16 = std::int16_t;
    using int32 = std::int32_t;
    using int64 = std::int64_t;

    using uint8 = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;

    using TypeId = uint32;

    template<typename TEnum>
    using isId = std::enable_if_t<std::is_same_v<std::underlying_type_t<TEnum>, TypeId>, bool>;

    template<typename T1, typename T2>
    using isBase = std::enable_if_t<std::is_base_of_v<T1, T2>, bool>;

    // TODO: Reconsider everything below this comment

    template <class T>
    using ref = std::shared_ptr<T>;

    template <class T>
    using weak = std::weak_ptr<T>;

    template<class T, typename ...TArgs>
    constexpr ref<T> createRef(TArgs&& ...args) {
        return std::make_shared<T>(std::forward<TArgs>(args)...);
    }

    template<class T>
    constexpr ref<T> makeRef(T* instance) {
        return std::shared_ptr<T>(instance);
    }

    template<class T>
    using unique = std::unique_ptr<T>;

    template<class T>
    using UniqueDel = std::unique_ptr<T, std::function<void(T*)>>;

    template<class T, typename ...TArgs>
    constexpr unique<T> createUnique(TArgs&& ...args) {
        return std::make_unique<T>(std::forward<TArgs>(args)...);
    }

    template<class T>
    constexpr unique<T> makeUnique(T* instance) {
        return std::unique_ptr<T>(instance);
    }

    template<class T>
    constexpr UniqueDel<T> makeUnique(T* instance, std::function<void(T*)> deleter) {
        return UniqueDel<T>(instance, deleter);
    }

    // TODO: Reconsider everything above this comment

    /**
     * @brief Cannot be copied nor moved to a different owner
     */
    class NoCopyNoMove {
    public:
        NoCopyNoMove(const NoCopyNoMove&) = delete;
        NoCopyNoMove& operator=(const NoCopyNoMove&) = delete;

        NoCopyNoMove(NoCopyNoMove&&) = delete;
        NoCopyNoMove& operator=(NoCopyNoMove&&) = delete;

        virtual ~NoCopyNoMove() = default;

    protected:
        NoCopyNoMove() = default;
    };
}


#endif //GOATENGINE_BASE_HPP
