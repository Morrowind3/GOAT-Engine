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
            static Input& getInstance() {
                static Input instance;
                return instance;
            }

            // Input
            void update();
            // Keyboard
            [[nodiscard]] bool anyKey() const;
            [[nodiscard]] bool anyKeyUp() const;
            [[nodiscard]] bool anyKeyDown() const;
            [[nodiscard]] bool getKey(KeyCode code) const;
            [[nodiscard]] bool getKeyUp(KeyCode code) const;
            [[nodiscard]] bool getKeyDown(KeyCode code) const;
            // Mouse
            [[nodiscard]] Point mousePosition() const;
            [[nodiscard]] bool anyMouse() const;
            [[nodiscard]] bool anyMouseUp() const;
            [[nodiscard]] bool anyMouseDown() const;
            [[nodiscard]] bool getMouse(MouseButton button) const;
            [[nodiscard]] bool getMouseUp(MouseButton button) const;
            [[nodiscard]] bool getMouseDown(MouseButton button) const;
            // Special
            void queueQuitEvent();
            [[nodiscard]] bool quitEvent() const;

        private:
            Input()= default;
            InputRegistry _registry{};
            // State
            bool _quitEvent = false;
            int _mousePositionX{}, _mousePositionY{};
        };
}

#endif //GOAT_ENGINE_INPUT_HPP