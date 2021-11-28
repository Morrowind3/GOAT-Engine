#include "VictoryScript.hpp"
#include <iostream>

VictoryScript::VictoryScript(bool active) : Script(active) {

}


void VictoryScript::OnStart() {
    std::cout << "A winner is you!" << std::endl;
}

