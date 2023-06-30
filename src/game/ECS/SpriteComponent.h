#pragma once
#include "ECS.h" 
#include "SDL.h"
class SpriteComponent : public Component {
    public: 
        SpriteComponent(const char* textureSheet, int x, int y);

        void init() override;

        void update() override;

        void draw() override;

    private: 
        int xpos;
        int ypos;
        SDL_Texture* objTexture;
        SDL_FRect srcRect, destRect;
};
