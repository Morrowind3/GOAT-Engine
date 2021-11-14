#include "ThirdTestScript.hpp"
#include <iostream>

ThirdTestScript::ThirdTestScript(bool active) : Script(active) {
}

void ThirdTestScript::OnUpdate(double deltaTime) {
   std::cout << ++_counter << '\n';
}
