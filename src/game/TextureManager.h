#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include "TextureManager.h"

class TextureManager {
    public: 
        static SDL_Texture* LoadTexture(const char* fileName);
        static void Draw(SDL_Texture* tex, SDL_FRect src, SDL_FRect dest);
};
