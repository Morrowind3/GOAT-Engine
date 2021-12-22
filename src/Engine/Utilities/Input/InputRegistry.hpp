#ifndef GOAT_ENGINE_INPUTREGISTRY_HPP
#define GOAT_ENGINE_INPUTREGISTRY_HPP

#include "PressState.hpp"
#include "KeyCode.hpp"
#include "MouseButton.hpp"
#include <map>

// Only callable by input
namespace Engine {
    class InputRegistry {
#ifdef TEST_ENVIRONMENT
        public:
#endif
        friend class Input;
        InputRegistry() = default;
        void flushForNextFrame();
        void storeKeyDown(KeyCode key);
        void storeKeyUp(KeyCode key);
        [[nodiscard]] bool anyKeyRegistered() const;
        [[nodiscard]] bool anyKeyInState(PressState state) const;
        [[nodiscard]] PressState keyStatus(KeyCode key) const;
        void storeMouseDown(MouseButton button);
        void storeMouseUp(MouseButton button);
        [[nodiscard]] bool anyMouseRegistered() const;
        [[nodiscard]] bool anyMouseInState(PressState state) const;
        [[nodiscard]] PressState mouseStatus(MouseButton button) const;
        std::map<KeyCode,PressState> _keyStates {};
        std::map<MouseButton,PressState> _mouseStates {};
    };
}

#endif //GOAT_ENGINE_INPUTREGISTRY_HPP
