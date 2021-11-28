//
// Created by Morrowind3 on 28/11/2021.
//

#ifndef GOAT_ENGINE_GOATSCRIPT_HPP
#define GOAT_ENGINE_GOATSCRIPT_HPP


#include "../../../GameObjects/Enemies/Goat.hpp"

class GoatScript : public Script {
public:
    GoatScript(Goat& goat, bool active): Script(active){};
    void onTriggerEnter2D(GameObject& object) override;

};


#endif //GOAT_ENGINE_GOATSCRIPT_HPP
