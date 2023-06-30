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

        void setAnimation(int numSprites, int offset, int delayFrames);

    private: 
        int cnt;
        int scale;
        int height;
        int width;
        bool animated = false;
        int spriteNum;
        int offset;
        int animationDelayFrames;
        PositionComponent* position;
        SDL_Texture* objTexture;
        SDL_FRect srcRect, destRect;
};
