//
// Created by Stijn van Loon on 12-11-2021.
//

#ifndef GOATENGINE_RENDERINGSYSTEM_HPP
#define GOATENGINE_RENDERINGSYSTEM_HPP

#include "../core/System.hpp"
#include "apis/RendererApi.hpp"

using namespace spic;

class RenderingSystem : public System {
public:
//    explicit RenderingSystem(const Scene *scene);

    void onInit();

    void onUpdate();

    void onUpdateDebug();

    void onDestroy();
};


#endif //GOATENGINE_RENDERINGSYSTEM_HPP
