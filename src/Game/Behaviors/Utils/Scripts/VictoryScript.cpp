//
// Created by Morrowind3 on 26/11/2021.
//

#include "VictoryScript.hpp"
#include <iostream>

VictoryScript::VictoryScript(bool active) : Script(active) {

}


void VictoryScript::OnStart() {
    std::cout << "A winner is you!" << std::endl;
}

