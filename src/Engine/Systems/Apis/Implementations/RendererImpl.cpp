#include "RendererImpl.hpp"

#include <algorithm>
#include <fstream>
#include "SDL_ttf.h"

using namespace Engine;

RendererImpl::RendererImpl(const std::string& name, std::string& iconPath) :
        _temporaryFixSoWeHaveSomethingToShowInClassTomorrow{}, // TODO: DELETE!
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

}

void RendererImpl::LoadTexture(const std::string& fileName) {
    _textures->store(fileName);
}

void RendererImpl::LoadFont(const std::string& fileName) {
    _fonts->store(fileName);
}

void RendererImpl::LoadMap(std::string& path, int tilesX, int tilesY, int tileSize, std::map<int, std::string>& tileDictionary) {
    // load all textures needed for map
    for (const auto &item : tileDictionary) {
        LoadTexture(item.second);
    }

    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    // dit gaat er fout: hij kopieerd telkens de voorgaande transform

    BeginRenderTick();
    for (int y = 0; y < tilesY; y++)
    {
        for (int x = 0; x < tilesX; x++) {
            while (tile == ' ' || tile == ',') {
                mapFile.ignore();
                mapFile.get(tile);
            }

            double posY {y * tileSize * 1.0};
            double posX {x * tileSize * 1.0};

            DrawTexture(
                    tileDictionary.at(atoi(&tile)),
                    Transform{Point{posX, posY}, 20, 0, 1, 1}
                    );

            Point p1 {_tickTextureCache.at(_tickTextureCache.size()-1).first->position};
            Point p2 {_tickTextureCache.at(0).first->position};


            mapFile.ignore();
        }
    }
    mapFile.close();
    EndRenderTick();
}

void RendererImpl::BeginRenderTick() {
    _tickTextureCache = {};
    _temporaryFixSoWeHaveSomethingToShowInClassTomorrow = {};
    SDL_RenderClear(_renderer.get());
}

void RendererImpl::DrawTexture(const std::string& name, const Transform& transform) {
    const auto& texture = _textures->get(name);
    _tickTextureCache.emplace_back(std::pair<const Transform*, const Texture*>{&transform, &texture});
}

void RendererImpl::DrawText(const std::string& text, uint8_t size, Color color, const std::string& fontName, const Transform& transform) {
    auto& font = _fonts->get(fontName);
    auto* texture = font.text(text,size,color);
//    _tickTextureCache.emplace_back(std::pair<const Transform*, const Texture*>{&transform, texture});
    _temporaryFixSoWeHaveSomethingToShowInClassTomorrow.push_back(texture);
}

bool tickTextureCacheSort(const std::pair<const Transform*, const Texture*>& a,
                          const std::pair<const Transform*, const Texture*>& b) {
    return a.first->layer < b.first->layer;
}

void RendererImpl::EndRenderTick() {
//    std::sort(_tickTextureCache.begin(), _tickTextureCache.end(), tickTextureCacheSort);

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

        SDL_RenderCopyEx(_renderer.get(), texture->texture(), &sourceRect, &destinationRect, transform->rotation, nullptr, flip);
    }
    SDL_RenderPresent(_renderer.get());

    // TODO: Delete this
    for (auto* deleteThis : _temporaryFixSoWeHaveSomethingToShowInClassTomorrow) {
        delete deleteThis;
    }
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
