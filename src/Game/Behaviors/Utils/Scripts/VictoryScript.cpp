#include "VictoryScript.hpp"
#include <iostream>

VictoryScript::VictoryScript(bool active) : Script(active) {

}


void VictoryScript::onStart() {
    std::cout << "A winner is you!" << std::endl;
}

