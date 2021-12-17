#include "RendererImpl.hpp"

#include <fstream>
#include "SDL_ttf.h"

using namespace Engine;

/// It usually isn't best practise to do this in the constructor, but else the smart pointers need to be hacked around with
RendererImpl::RendererImpl(const std::string& name, const std::string& iconPath, const std::string& cursor) :
        _sdlStatus{SDL_Init(SDL_INIT_EVERYTHING)},
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window*)>{
                SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800,
                                 SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED), SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)>{SDL_CreateRenderer(_window.get(), -1, 0), SDL_DestroyRenderer}} {
    TTF_Init();
    SDL_SetWindowIcon(_window.get(), IMG_Load(iconPath.c_str()));
    SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
    auto cursorSurface = IMG_Load(cursor.c_str());
    auto sdlCursor = SDL_CreateColorCursor(cursorSurface, 8, 8);
    SDL_SetCursor(sdlCursor);
}

void RendererImpl::initialize() {
    // TODO: Move as much of the constructor into here as possible
}

void RendererImpl::setViewPort(Point dimensions) {
    if (!_resizeForFirstSceneHasTakenPlace) {
        SDL_DisplayMode DM;
        SDL_GetCurrentDisplayMode(0, &DM);
        auto width = DM.w;
        auto height = DM.h;

        SDL_SetWindowSize(_window.get(), width, height);
        SDL_MaximizeWindow(_window.get());
        _resizeForFirstSceneHasTakenPlace = true;
    }
    SDL_RenderSetLogicalSize(_renderer.get(), dimensions.x, dimensions.y);
    _engineCalls.viewPortSize(dimensions);
}

void RendererImpl::loadTexture(const std::string& fileName) {
    try {
        _textures->store(fileName);
    } catch (const std::runtime_error& error) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", error.what());
        exit(101);
    }
}

void RendererImpl::loadFont(const std::string& fileName) {
    if (fileName.empty()) return; // Ignore an invalid font
    try {
        _fonts->store(fileName);
    } catch (const std::runtime_error& error) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", error.what());
        exit(102);
    }
}

void RendererImpl::beginRenderTick() {
    _tickTextureCache.clear();
    SDL_RenderClear(_renderer.get());

    // Window is resizable so engine must know the current size
    int windowWidth, windowHeight;
    SDL_GetWindowSize(_window.get(), &windowWidth, &windowHeight);
    _engineCalls.windowSize({windowWidth,windowHeight});
}

void RendererImpl::drawTexture(const std::string& name, const std::shared_ptr<Transform>& transform) {
    const auto& texture = _textures->get(name);
    _tickTextureCache.emplace_back(TickTextureCacheData{*transform, &texture});
}

void RendererImpl::drawText(const std::string& text, uint8_t size, Color color, const std::string& fontName, const std::shared_ptr<Transform>& transform) {
    if (fontName.empty()) return; // Ignore text with an invalid font
    auto& font = _fonts->get(fontName);
    std::shared_ptr<Texture> texture = font.text(text,size,color);
    _tickTextureCache.emplace_back(TickTextureCacheData{*transform, texture.get()});
}

void RendererImpl::endRenderTick() {
    std::sort(_tickTextureCache.begin(), _tickTextureCache.end());
    for (auto& drawable: _tickTextureCache) {
        draw(drawable);
    }
    SDL_RenderPresent(_renderer.get());
}

void RendererImpl::resetForNextScene() {
    _textures->resetForNextScene();
    _fonts->resetForNextScene();
    _textures = std::make_unique<TextureManager>(_renderer.get());
    _fonts = std::make_unique<FontManager>(_renderer.get());
}

void RendererImpl::end() {
    TTF_Quit();
    SDL_Quit();
}

/// Draws texture to the screen
void RendererImpl::draw(TickTextureCacheData& drawable) {
    auto& transform = drawable.transform;
    auto& texture = drawable.data;
    auto viewPortSize = _engineCalls.viewPortSize();

    // Don't render off-screen
    if (!transform._isGui && !transform._isParallax) {
        if (transform.position.x > viewPortSize.x && transform.position.y > viewPortSize.y) return;
        if (transform.position.x < -400 && transform.position.y < -400) return;
    }

    SDL_Rect sourceRect{}, destinationRect{};

    // Do NOT cast transform to a static int because of rounding errors!!
    sourceRect.w = transform.scaleWidth * texture->width();
    sourceRect.h = transform.scaleHeight * texture->height();

    destinationRect.x = transform.position.x;
    destinationRect.y = transform.position.y;
    destinationRect.w = transform.forcedWidth != 0 ? transform.forcedWidth : transform.scaleWidth * texture->width();
    destinationRect.h = transform.forcedHeight != 0 ? transform.forcedHeight : transform.scaleWidth * texture->height();

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

    SDL_RenderCopyEx(_renderer.get(), texture->texture(), &sourceRect, &destinationRect, transform.rotation, nullptr, flip);
}