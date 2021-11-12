//
// Created by Stijn van Loon on 12-11-2021.
//

#ifndef GOATENGINE_RENDERERAPI_HPP
#define GOATENGINE_RENDERERAPI_HPP

#include <string>
//#include "../API/GameObjects/Transform.hpp"

namespace RenderApi {
    void loadTexture(const std::string& fileName);
    void beginTick();
//    void drawTexture(const std::string& spriteName, const Transform& transform);
    void endTick();
    void end();
}


#endif //GOATENGINE_RENDERERAPI_HPP
