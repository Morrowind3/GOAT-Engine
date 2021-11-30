#include "InputPrintScript.hpp"
#include "../../../Keys.hpp"

InputPrintScript::InputPrintScript(bool active) : Script(active) {
}

void InputPrintScript::onUpdate(double deltaTime) {
//    if (_globals.gameExists(Keys::INPUT_DEBUG)) {
//        _debug.log("---BEGIN INPUT PRINT SCRIPT---");
//        const std::string prefix{"(INPUT PRINT SCRIPT) "};
//        if (_input.AnyKey()) _debug.log(prefix+"AnyKey");
//        if (_input.AnyKeyUp()) _debug.log(prefix+"AnyKeyUp");
//        if (_input.AnyKeyDown()) _debug.log(prefix+"AnyKeyDown");
//        if (_input.GetKey(KeyCode::ENTER)) _debug.log(prefix+"GetKey");
//        if (_input.GetKeyUp(KeyCode::ENTER)) _debug.log(prefix+"GetKeyUp");
//        if (_input.GetKeyDown(KeyCode::ENTER)) _debug.log(prefix+"GetKeyDown");
//        if (_input.AnyMouse()) _debug.log(prefix+"AnyMouse");
//        if (_input.AnyMouseUp()) _debug.log(prefix+"AnyMouseUp");
//        if (_input.AnyMouseDown()) _debug.log(prefix+"AnyMouseDown");
//        if (_input.GetMouse(MouseButton::RIGHT)) _debug.log(prefix + "GetMouse");
//        if (_input.GetMouseUp(MouseButton::RIGHT)) _debug.log(prefix+"GetMouseUp");
//        if (_input.GetMouseDown(MouseButton::RIGHT)) _debug.log(prefix+"GetMouseDown");
//        _debug.log(prefix+"Mouse X: "+std::to_string(_input.MousePosition().x)+" Mouse Y: "+std::to_string(_input.MousePosition().y));
//        _debug.log("---END INPUT PRINT SCRIPT---");
//    }
}
