//
// Created by Stijn van Loon on 12-11-2021.
//

#ifndef GOATENGINE_RENDERERIMPL_HPP
#define GOATENGINE_RENDERERIMPL_HPP

#include <memory>
#include <map>
#include <string>

#include "SDL.h"
#include "SDL_image.h"
//#include "../../API/GameObjects/Transform.hpp"

class RendererImpl {
public:
    RendererImpl();

    void loadTexture(const std::string &fileName);

    void beginRenderTick();

//    void drawTexture(const std::string &texture, const Transform &location);

    void endRenderTick();

    void end();

private:
    int _sdlStatus;
    std::unique_ptr<std::map<std::string, SDL_Texture *>> _textures;
    std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> _window;
    std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)> _renderer;
};


#endif //GOATENGINE_RENDERERIMPL_HPP
