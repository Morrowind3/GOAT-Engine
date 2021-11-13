#include "RendererImpl.hpp"

using namespace Engine;

RendererImpl::RendererImpl() :
        _sdlStatus{SDL_Init(SDL_INIT_EVERYTHING)},
        _textures(std::make_unique<TextureManager>()),
        // TODO: Make window parameters variable
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window*)>{
                SDL_CreateWindow("Engine PoC", 200, 200, 640, 480, 0), SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)>{SDL_CreateRenderer(_window.get(), -1, 0),
                                                                         SDL_DestroyRenderer}} {
    SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
}

void RendererImpl::LoadTexture(const std::string& fileName) {
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), tempSurface);
    SDL_FreeSurface(tempSurface);
    _textures->store(fileName, texture);
}

void RendererImpl::BeginRenderTick() {
    SDL_RenderClear(_renderer.get());
}

void RendererImpl::DrawTexture(const std::string& name, const Transform& transform) {
    auto texture = _textures->get(name);
    SDL_Rect source{}, destination{};

    source.x = source.y = 0;
    source.w = static_cast<int>(transform.width) * texture.width();
    source.h = static_cast<int>(transform.height) * texture.height();

    destination.x = static_cast<int>(transform.position.x);
    destination.y = static_cast<int>(transform.position.y);
    destination.w = static_cast<int>(transform.width) * texture.width();
    destination.h = static_cast<int>(transform.height) * texture.height();

    SDL_RenderCopy(_renderer.get(), texture.texture(), &source, &destination);
}

void RendererImpl::EndRenderTick() {
    SDL_RenderPresent(_renderer.get());
}

void RendererImpl::End() {
    SDL_Quit();
}
