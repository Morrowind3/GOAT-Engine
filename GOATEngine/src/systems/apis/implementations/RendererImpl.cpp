#include "RendererImpl.hpp"

#include <string>

// TODO: Fix this
std::string TITLE = "Test";
int SCREENWIDTH = 800;
int SCREENHEIGHT = 600;

namespace Engine {
    RendererImpl::RendererImpl() :
            _sdlStatus{SDL_Init(SDL_INIT_EVERYTHING)},
            _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window *)>{
                    SDL_CreateWindow(TITLE.c_str(), 200, 200, SCREENWIDTH, SCREENHEIGHT, 0), SDL_DestroyWindow}},
            _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)>
                    {SDL_CreateRenderer(_window.get(), -1, 0), SDL_DestroyRenderer}} {
        SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
    }

    Texture RendererImpl::loadTexture(const std::string &fileName) {
        SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), tempSurface);
        SDL_FreeSurface(tempSurface);
        return Texture{texture};
    }

    void RendererImpl::beginRenderTick() {
        SDL_RenderClear(_renderer.get());
    }

    void RendererImpl::drawTexture(const Texture& texture, const Transform& transform)
    {
        int textureWidth, textureHeight;
        SDL_Rect source{}, destination{};

        source.x = source.y = 0;
        source.w = static_cast<int>(transform.scaleX()) * texture.width();
        source.h = static_cast<int>(transform.scaleY()) * texture.height();

        destination.x = static_cast<int>(transform.position().x());
        destination.y = static_cast<int>(transform.position().y());
        destination.w = static_cast<int>(transform.scaleX()) * textureWidth;
        destination.h = static_cast<int>(transform.scaleY()) * textureHeight;

        SDL_RenderCopy(_renderer.get(), texture.texture(), &source, &destination);
    }

    void RendererImpl::endRenderTick() {
        SDL_RenderPresent(_renderer.get());
    }

    void RendererImpl::end() {
        SDL_Quit();
    }
}
