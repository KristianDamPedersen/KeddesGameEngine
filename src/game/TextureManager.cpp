#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(fileName);
    if(!tempSurface) {
        std::cout << "Failed to load image!" << std::endl;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_DestroySurface(tempSurface);
    return tex;
}


void TextureManager::Draw(SDL_Texture* tex, SDL_Renderer* renderer, SDL_FRect src, SDL_FRect dest) {
    SDL_RenderTexture(renderer, tex, &src, &dest);
}
