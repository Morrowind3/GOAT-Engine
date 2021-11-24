#include "RendererImpl.hpp"

#include <algorithm>
#include <fstream>
#include "SDL_ttf.h"

using namespace Engine;

RendererImpl::RendererImpl(const std::string& name, std::string& iconPath, std::string& cursor) :
        _sdlStatus{SDL_Init(SDL_INIT_EVERYTHING)},
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window*)>{
                SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800,
                                 SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED), SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)>{SDL_CreateRenderer(_window.get(), -1, 0), SDL_DestroyRenderer}} {
    TTF_Init();
    _textures = std::make_unique<TextureManager>(_renderer.get());
    _fonts = std::make_unique<FontManager>(_renderer.get());
    SDL_SetWindowIcon(_window.get(), IMG_Load(iconPath.c_str()));
    SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
    SDL_RenderSetLogicalSize(_renderer.get(), 1920, 985);

    auto cursorSurface = IMG_Load(cursor.c_str());
    auto sdlCursor = SDL_CreateColorCursor(cursorSurface, 8, 8);
    SDL_SetCursor(sdlCursor);

}

void RendererImpl::LoadTexture(const std::string& fileName) {
    _textures->store(fileName);
}

void RendererImpl::LoadFont(const std::string& fileName) {
    _fonts->store(fileName);
}

void RendererImpl::BeginRenderTick() {
    _tickTextureCache = {};
    SDL_RenderClear(_renderer.get());
}

void RendererImpl::DrawTexture(const std::string& name, const Transform& transform) {
    const auto& texture = _textures->get(name);
    _tickTextureCache.emplace_back(std::pair<const Transform*, const Texture*>{&transform, &texture});
}

void RendererImpl::DrawText(const std::string& text, uint8_t size, Color color, const std::string& fontName, const Transform& transform) {
    auto& font = _fonts->get(fontName);
    std::shared_ptr<Texture> texture = font.text(text,size,color);
    _tickTextureCache.emplace_back(std::pair<const Transform*, const Texture*>{&transform, texture.get()});
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

        // transform NIET naar een static int casten!! gaat fout met afronden
        sourceRect.w = transform->scaleWidth * texture->width();
        sourceRect.h = transform->scaleHeight * texture->height();

        destinationRect.x = static_cast<int>(transform->position.x);
        destinationRect.y = static_cast<int>(transform->position.y);
        destinationRect.w = transform->scaleWidth * texture->width();
        destinationRect.h = transform->scaleWidth * texture->height();

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

        SDL_RenderCopyEx(_renderer.get(), texture->texture(), &sourceRect, &destinationRect, transform->rotation, nullptr, flip);
    }
    SDL_RenderPresent(_renderer.get());
}

void RendererImpl::End() {
    //TODO correctly freeing application
//    SDL_FreeCursor(cursor);
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
