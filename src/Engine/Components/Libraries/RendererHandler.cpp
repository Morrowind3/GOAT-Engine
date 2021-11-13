#include "RendererHandler.hpp"

#include <utility>
#include <stdexcept>

RendererHandler::RendererHandler() : 
    _sdlStatus { SDL_Init(SDL_INIT_EVERYTHING) },
    _textures(std::make_unique<std::map<std::string, SDL_Texture*>>()),
    _window { std::unique_ptr<SDL_Window,void(*)(SDL_Window*)> { SDL_CreateWindow("Engine PoC",200,200,640,480,0), SDL_DestroyWindow} },
    _renderer { std::unique_ptr<SDL_Renderer,void(*)(SDL_Renderer*)> { SDL_CreateRenderer(_window.get(),-1,0), SDL_DestroyRenderer} }
{
    SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
}

void RendererHandler::LoadTexture(const std::string& fileName)
{
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    SDL_Texture* tex = SDL_CreateTextureFromSurface(_renderer.get(), tempSurface);
    SDL_FreeSurface(tempSurface);
    std::pair<std::string, SDL_Texture*> insertPair {fileName,tex};
    _textures->insert(insertPair);
}

void RendererHandler::BeginRenderTick()
{
    SDL_RenderClear(_renderer.get());
}

void RendererHandler::DrawTexture(const std::string& name, const Transform& transform)
{
    auto texture = _textures->at(name);
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture,nullptr,nullptr,&textureWidth,&textureHeight);
    SDL_Rect source{}, destination{};

    source.x = source.y = 0;
    source.w = static_cast<int>(transform.width) * textureWidth;
    source.h = static_cast<int>(transform.height) * textureHeight;

    destination.x = static_cast<int>(transform.position.x);
    destination.y = static_cast<int>(transform.position.y);
    destination.w = static_cast<int>(transform.width) * textureWidth;
    destination.h = static_cast<int>(transform.height) * textureHeight;

    SDL_RenderCopy(_renderer.get(), texture, &source, &destination);
}

void RendererHandler::EndRenderTick()
{
    SDL_RenderPresent(_renderer.get());
}

void RendererHandler::End()
{
    SDL_Quit();
}
