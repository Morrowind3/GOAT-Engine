#include "RendererImpl.hpp"

using namespace Engine;

RendererImpl::RendererImpl(const std::string& name, std::string& iconPath) :
        _sdlStatus{SDL_Init(SDL_INIT_EVERYTHING)},
        _textures(std::make_unique<TextureManager>()),
        // TODO: Make window parameters variable
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window*)>{
                SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800,
                                 SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED), SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)>{SDL_CreateRenderer(_window.get(), -1, 0),
                                                                         SDL_DestroyRenderer}} {
    // set icon
    SDL_SetWindowIcon(_window.get(), IMG_Load(iconPath.c_str()));


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
    SDL_Rect sourceRect{}, destinationRect{};

    sourceRect.x = sourceRect.y = 0;
    sourceRect.w = static_cast<int>(transform.scaleWidth) * texture.width();
    sourceRect.h = static_cast<int>(transform.scaleHeight) * texture.height();

    destinationRect.x = static_cast<int>(transform.position.x);
    destinationRect.y = static_cast<int>(transform.position.y);
    destinationRect.w = static_cast<int>(transform.scaleWidth) * texture.width();
    destinationRect.h = static_cast<int>(transform.scaleWidth) * texture.height();

    SDL_RendererFlip flip;
    switch (transform.flip) {
        case FLIP::FLIP_NONE:
            flip = SDL_FLIP_NONE;
            break;
        case FLIP::FLIP_HORIZONTAL:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case FLIP::FLIP_VERTICAL:
            flip = SDL_FLIP_VERTICAL;
            break;
    }

    SDL_RenderCopyEx(_renderer.get(), texture.texture(), &sourceRect, &destinationRect, transform.rotation, nullptr, flip);
}

void RendererImpl::EndRenderTick() {
    SDL_RenderPresent(_renderer.get());
}

void RendererImpl::End() {
    SDL_Quit();
}
