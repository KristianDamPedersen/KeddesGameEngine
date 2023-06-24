#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren) {
    SDL_Surface* tempSurface = IMG_Load(fileName);
    if(!tempSurface) {
        std::cout << "Failed to load image!" << std::endl;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_DestroySurface(tempSurface);
    return tex;
}
