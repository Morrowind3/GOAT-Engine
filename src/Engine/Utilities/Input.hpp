//
// Created by Morrowind3 on 14/11/2021.
//

#ifndef GOAT_ENGINE_INPUT_HPP
#define GOAT_ENGINE_INPUT_HPP


#include "../API/GameObjects/Point.hpp"

namespace Engine{

    class Input {
        public:
            enum class KeyCode {
                UNKNOWN = 0,
                ENTER = '\r',
                ESCAPE = '\x1B',
                BACKSPACE = '\b',
                TAB = '\t',
                SPACE = ' ',
                EXCLAMATION_MARK = '!',
                DOUBLE_QUOTE = '"',
                HASH = '#',
                PERCENT = '%',
                DOLLAR = '$',
                AMPERSAND = '&',
                QUOTE = '\'',
                LEFT_PARENTHESIS = '(',
                RIGHT_PARENTHESIS = ')',
                ASTERISK = '*',
                PLUS = '+',
                COMMA = ',',
                MINUS = '-',
                PERIOD = '.',
                SLASH = '/',
                NUMBER_0 = '0',
                NUMBER_1 = '1',
                NUMBER_2 = '2',
                NUMBER_3 = '3',
                NUMBER_4 = '4',
                NUMBER_5 = '5',
                NUMBER_6 = '6',
                NUMBER_7 = '7',
                NUMBER_8 = '8',
                NUMBER_9 = '9',
                COLON = ':',
                SEMICOLON = ';',
                LESS = '<',
                EQUALS = '=',
                GREATER = '>',
                QUESTION_MARK = '?',
                AT = '@',
                LEFT_BRACKET = '[',
                BACKSLASH = '\\',
                RIGHT_BRACKET = ']',
                CARET = '^',
                UNDERSCORE = '_',
                BACKQUOTE = '`',
                A = 'a',
                B = 'b',
                C = 'c',
                D = 'd',
                E = 'e',
                F = 'f',
                G = 'g',
                H = 'h',
                I = 'i',
                J = 'j',
                K = 'k',
                L = 'l',
                M = 'm',
                N = 'n',
                O = 'o',
                P = 'p',
                Q = 'q',
                R = 'r',
                S = 's',
                T = 't',
                U = 'u',
                V = 'v',
                W = 'w',
                X = 'x',
                Y = 'y',
                Z = 'z',

                CAPSLOCK = 0x40000039,
                F1 = 0x4000003A,
                F2 = 0x4000003B,
                F3 = 0x4000003C,
                F4 = 0x4000003D,
                F5 = 0x4000003E,
                F6 = 0x4000003F,
                F7 = 0x40000040,
                F8 = 0x40000041,
                F9 = 0x40000042,
                F10 = 0x40000043,
                F11 = 0x40000044,
                F12 = 0x40000045,

                PRINTSCREEN = 0x40000046,
                SCROLLLOCK = 0x40000047,
                PAUSE = 0x40000048,
                INSERT = 0x40000049,
                HOME = 0x4000004A,
                PAGE_UP = 0x4000004B,
                DELETE = '\x7F',
                END = 0x4000004D,
                PAGE_DOWN = 0x4000004E,
                RIGHT = 0x4000004F,
                LEFT = 0x40000050,
                DOWN = 0x40000051,
                UP = 0x40000052,

                NUMLOCK_CLEAR = 0x40000053,
                NUMPAD_DIVIDE = 0x40000054,
                NUMPAD_MULTIPLY = 0x40000055,
                NUMPAD_MINUS = 0x40000056,
                NUMPAD_PLUS = 0x40000057,
                NUMPAD_ENTER = 0x40000058,
                NUMPAD_1 = 0x40000059,
                NUMPAD_2 = 0x4000005A,
                NUMPAD_3 = 0x4000005B,
                NUMPAD_4 = 0x4000005C,
                NUMPAD_5 = 0x4000005D,
                NUMPAD_6 = 0x4000005E,
                NUMPAD_7 = 0x4000005F,
                NUMPAD_8 = 0x40000060,
                NUMPAD_9 = 0x40000061,
                NUMPAD_0 = 0x40000062,
                NUMPAD_PERIOD = 0x40000063,

                LCTRL = 0x400000E0,
                LSHIFT = 0x400000E1,
                LALT = 0x400000E2,
                LGUI = 0x400000E3,
                RCTRL = 0x400000E4,
                RSHIFT = 0x400000E5,
                RALT = 0x400000E6,
                RGUI = 0x400000E7,
            };
            enum class MouseButton {
                LEFT = 1,
                MIDDLE = 2,
                RIGHT = 3
            };
            Input(Input const&)  = delete;
            void operator=(Input const&)  = delete;
            static Input& getInstance()
            {
                static Input instance;
                return instance;
            }

            void Init();
            void Update();
            const bool AnyKey();
            const bool AnyKeyUp();
            const bool AnyKeydown();
            const bool GetKey(KeyCode code);
            const bool GetKeyUp(KeyCode code);
            const bool GetKeyDown(KeyCode code);
            const Point MousePosition();
            const bool AnyMouse();
            const bool AnyMouseUp();
            const bool AnyMouseDown();
            const bool GetMouseButton(MouseButton button);
            const bool GetMouseUp(MouseButton button);
            const bool GetMouseDown(MouseButton button);
        private:
            Input(){};
        };
}


#endif //GOAT_ENGINE_INPUT_HPP