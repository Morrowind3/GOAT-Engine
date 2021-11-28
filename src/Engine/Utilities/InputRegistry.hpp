#ifndef GOAT_ENGINE_INPUTREGISTRY_HPP
#define GOAT_ENGINE_INPUTREGISTRY_HPP

#include "Input/PressState.hpp"
#include "Input/KeyCode.hpp"
#include "Input/MouseButton.hpp"
#include <map>

// Only callable by input
namespace Engine {
    class InputRegistry {
        friend class Input;
        InputRegistry() = default;
        void FlushForNextFrame();
        void StoreKeyDown(KeyCode key);
        void StoreKeyUp(KeyCode key);
        [[nodiscard]] bool AnyKeyRegistered() const;
        [[nodiscard]] bool AnyKeyInState(PressState state) const;
        [[nodiscard]] PressState KeyStatus(KeyCode key) const;
        void StoreMouseDown(MouseButton button);
        void StoreMouseUp(MouseButton button);
        [[nodiscard]] bool AnyMouseRegistered() const;
        [[nodiscard]] bool AnyMouseInState(PressState state) const;
        [[nodiscard]] PressState MouseStatus(MouseButton button) const;
        std::map<KeyCode,PressState> _keyStates {};
        std::map<MouseButton,PressState> _mouseStates {};
    };
}

#endif //GOAT_ENGINE_INPUTREGISTRY_HPP
