#pragma once
#include "ECS.h" 
#include "SDL.h"
class SpriteComponent : public Component {
    public: 
        SpriteComponent(const char* textureSheet, int x, int y, int s);

        void init() override;

        void update() override;

        void draw() override;

    private: 
        int xpos;
        int ypos;
        int scale;
        SDL_Texture* objTexture;
        SDL_FRect srcRect, destRect;
};
