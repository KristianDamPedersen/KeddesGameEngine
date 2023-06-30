#pragma once
#include "ECS.h" 
#include "SDL.h"
#include "PositionComponent.h"
class SpriteComponent : public Component {
    public: 
        SpriteComponent(const char* textureSheet, PositionComponent* posComp, int h, int w, int s);

        void init() override;

        void update() override;

        void draw() override;

    private: 
        int scale;
        int height;
        int width;
        PositionComponent* position;
        SDL_Texture* objTexture;
        SDL_FRect srcRect, destRect;
};
