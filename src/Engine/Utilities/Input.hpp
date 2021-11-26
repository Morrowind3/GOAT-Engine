#ifndef GOAT_ENGINE_INPUT_HPP
#define GOAT_ENGINE_INPUT_HPP

#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include <map>
#include <vector>
#include "../API/GameObjects/Point.hpp"
#include "Input/KeyCode.hpp"
#include "Input/MouseButton.hpp"
#include "InputRegistry.hpp"

namespace Engine {
    class Input {
        public:
            // TODO: Move constructor rule of five
            Input(Input const&) = delete;
            void operator=(Input const&) = delete;
            static Input& GetInstance() {
                static Input instance;
                return instance;
            }

            // Input
            void Update();
            // Keyboard
            [[nodiscard]] bool AnyKey() const;
            [[nodiscard]] bool AnyKeyUp() const;
            [[nodiscard]] bool AnyKeyDown() const;
            [[nodiscard]] bool GetKey(KeyCode code) const;
            [[nodiscard]] bool GetKeyUp(KeyCode code) const;
            [[nodiscard]] bool GetKeyDown(KeyCode code) const;
            // Mouse
            [[nodiscard]] Point MousePosition() const;
            [[nodiscard]] bool AnyMouse() const;
            [[nodiscard]] bool AnyMouseUp() const;
            [[nodiscard]] bool AnyMouseDown() const;
            [[nodiscard]] bool GetMouse(MouseButton button) const;
            [[nodiscard]] bool GetMouseUp(MouseButton button) const;
            [[nodiscard]] bool GetMouseDown(MouseButton button) const;
            // Special
            void QueueQuitEvent();
            [[nodiscard]] bool QuitEvent() const;

        private:
            Input()= default;
            InputRegistry _registry{};
            // State
            bool _quitEvent = false;
            int _mousePositionX{}, _mousePositionY{};
        };
}

#endif //GOAT_ENGINE_INPUT_HPP