//
// Created by Morrowind3 on 08/12/2021.
//

#include "CloudBehavior.hpp"
#include "CloudScript.hpp"
#include "../../../Keys.hpp"

CloudBehavior::CloudBehavior(Cloud& cloud, bool active) : Behavior(active){
    scripts.insert(std::make_pair(Keys::CLOUDS, std::make_shared<CloudScript>(cloud, true)));
}
