#include "RendererImpl.hpp"

#include <algorithm>
#include "SDL_ttf.h"

using namespace Engine;

RendererImpl::RendererImpl(const std::string& name, std::string& iconPath) :
        _sdlStatus{SDL_Init(SDL_INIT_EVERYTHING)},
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window*)>{
                SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800,
                                 SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED), SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)>{SDL_CreateRenderer(_window.get(), -1, 0),
                                                                         SDL_DestroyRenderer}} {
    TTF_Init();
    _textures = std::make_unique<TextureManager>(_renderer.get());
    _fonts = std::make_unique<FontManager>();
    SDL_SetWindowIcon(_window.get(), IMG_Load(iconPath.c_str()));
    SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
}

void RendererImpl::LoadTexture(const std::string& fileName) {
    _textures->store(fileName);
}

void RendererImpl::LoadFont(const std::string& name, const std::string& path, Uint8 size) {
    _fonts->store(name, path, size);
}

void RendererImpl::BeginRenderTick() {
    _tickTextureCache = {};
    SDL_RenderClear(_renderer.get());
}

void RendererImpl::DrawTexture(const std::string& name, const Transform& transform) {
    const auto& texture = _textures->get(name);
    _tickTextureCache.emplace_back(std::pair<const Transform*, const Texture*>{&transform, &texture});
}

// TODO: This is mega temporary
void RendererImpl::DrawText(const std::string& fontName, const std::string& text) {
    auto* font = _fonts->get(fontName);
    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {0, 0, texW, texH};
    SDL_RenderCopy(_renderer.get(), texture, NULL, &dstrect);
    SDL_RenderPresent(_renderer.get());
}

bool tickTextureCacheSort(const std::pair<const Transform*, const Texture*>& a,
                          const std::pair<const Transform*, const Texture*>& b) {
    return a.first->layer < b.first->layer;
}

void RendererImpl::EndRenderTick() {
    std::sort(_tickTextureCache.begin(), _tickTextureCache.end(), tickTextureCacheSort);
    for (auto& drawable: _tickTextureCache) {
        auto& transform = drawable.first;
        auto& texture = drawable.second;

        SDL_Rect sourceRect{}, destinationRect{};

        sourceRect.x = sourceRect.y = 0;
        sourceRect.w = static_cast<int>(transform->scaleWidth) * texture->width();
        sourceRect.h = static_cast<int>(transform->scaleHeight) * texture->height();

        destinationRect.x = static_cast<int>(transform->position.x);
        destinationRect.y = static_cast<int>(transform->position.y);
        destinationRect.w = static_cast<int>(transform->scaleWidth) * texture->width();
        destinationRect.h = static_cast<int>(transform->scaleWidth) * texture->height();

        SDL_RendererFlip flip;
        switch (transform->flip) {
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

        SDL_RenderCopyEx(_renderer.get(), texture->texture(), &sourceRect, &destinationRect, transform->rotation,
                         nullptr, flip);
    }
    SDL_RenderPresent(_renderer.get());
}

void RendererImpl::End() {
    //TODO correctly freeing application
//    SDL_DestroyTexture(texture);
//    SDL_FreeSurface(surface);
//    TTF_CloseFont(font);
//    SDL_RenderClear(renderer);
//    TTF_Quit();
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
    SDL_Quit();
    TTF_Quit();
}


