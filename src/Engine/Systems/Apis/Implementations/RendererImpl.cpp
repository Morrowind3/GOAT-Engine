#include "RendererImpl.hpp"

using namespace Engine;

RendererImpl::RendererImpl() :
        _sdlStatus{SDL_Init(SDL_INIT_EVERYTHING)},
        _textures(std::make_unique<std::map<std::string, SDL_Texture*>>()),
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window*)>{
                SDL_CreateWindow("Engine PoC", 200, 200, 640, 480, 0), SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)>{SDL_CreateRenderer(_window.get(), -1, 0),
                                                                         SDL_DestroyRenderer}} {
    SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
}

void RendererImpl::LoadTexture(const std::string& fileName) {
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    SDL_Texture* tex = SDL_CreateTextureFromSurface(_renderer.get(), tempSurface);
    SDL_FreeSurface(tempSurface);
    std::pair<std::string, SDL_Texture*> insertPair{fileName, tex};
    _textures->insert(insertPair);
}

void RendererImpl::BeginRenderTick() {
    SDL_RenderClear(_renderer.get());
}

void RendererImpl::DrawTexture(const std::string& name, const Transform& transform) {
    auto texture = _textures->at(name);
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);
    SDL_Rect sourceRect{}, destinationRect{};

    sourceRect.x = sourceRect.y = 0;
    sourceRect.w = static_cast<int>(transform._scaleWidth) * textureWidth;
    sourceRect.h = static_cast<int>(transform._scaleheight) * textureHeight;

    destinationRect.x = static_cast<int>(transform._position.x);
    destinationRect.y = static_cast<int>(transform._position.y);
    destinationRect.w = static_cast<int>(transform._scaleWidth) * textureWidth;
    destinationRect.h = static_cast<int>(transform._scaleWidth) * textureHeight;

    SDL_RendererFlip flip;
    switch (transform._flip) {
        case FLIP_NONE:
            flip = SDL_FLIP_NONE;
            break;
        case FLIP_HORIZONTAL:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case FLIP_VERTICAL:
            flip = SDL_FLIP_VERTICAL;
            break;
    }

    SDL_RenderCopyEx(_renderer.get(), texture, &sourceRect, &destinationRect, transform._rotation, nullptr, flip);
}

void RendererImpl::EndRenderTick() {
    SDL_RenderPresent(_renderer.get());
}

void RendererImpl::End() {
    SDL_Quit();
}
