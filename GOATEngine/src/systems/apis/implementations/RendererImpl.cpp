//
// Created by Stijn van Loon on 12-11-2021.
//

#include "RendererImpl.hpp"
#include <utility>
#include <stdexcept>
#include <string>

extern std::string TITLE;
extern int SCREENWIDTH;
extern int SCREENHEIGHT;

RendererImpl::RendererImpl() :
        _sdlStatus{SDL_Init(SDL_INIT_EVERYTHING)},
        _textures(std::make_unique<std::map<std::string, SDL_Texture *>>()),
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window *)>{
                SDL_CreateWindow(TITLE.c_str(), 200, 200, SCREENWIDTH, SCREENHEIGHT, 0), SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)>{SDL_CreateRenderer(_window.get(), -1, 0),
                                                                          SDL_DestroyRenderer}} {
    SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
}

void RendererImpl::loadTexture(const std::string &fileName) {
    SDL_Surface *tempSurface = IMG_Load(fileName.c_str());
    SDL_Texture *tex = SDL_CreateTextureFromSurface(_renderer.get(), tempSurface);
    SDL_FreeSurface(tempSurface);
    std::pair<std::string, SDL_Texture *> insertPair{fileName, tex};
    _textures->insert(insertPair);
}

void RendererImpl::beginRenderTick() {
    SDL_RenderClear(_renderer.get());
}

//void RendererImpl::drawTexture(const std::string& name, const Transform& transform)
//{
//    auto texture = _textures->at(name);
//    int textureWidth, textureHeight;
//    SDL_QueryTexture(texture,nullptr,nullptr,&textureWidth,&textureHeight);
//    SDL_Rect source{}, destination{};
//
//    source.x = source.y = 0;
//    source.w = static_cast<int>(transform.width) * textureWidth;
//    source.h = static_cast<int>(transform.height) * textureHeight;
//
//    destination.x = static_cast<int>(transform.position.x);
//    destination.y = static_cast<int>(transform.position.y);
//    destination.w = static_cast<int>(transform.width) * textureWidth;
//    destination.h = static_cast<int>(transform.height) * textureHeight;
//
//    SDL_RenderCopy(_renderer.get(), texture, &source, &destination);
//}

void RendererImpl::endRenderTick() {
    SDL_RenderPresent(_renderer.get());
}

void RendererImpl::end() {
    SDL_Quit();
}