#pragma once
#include "ECS.h" 
#include "SDL.h"
#include "PositionComponent.h"
class SpriteComponent : public Component {
    public: 

        enum class FlipState {
            none,
            horizontal,
            vertical
        };

        SpriteComponent(const char* textureSheet, PositionComponent* posComp, int h, int w, int s);

        void init() override;

        void update() override;

        void draw() override;

        void setAnimation(int numSprites, int offset, int delayFrames);
        
        void setFlipState(FlipState flipState);
        
        FlipState getFlipState();
        

    private: 
        int cnt;
        int scale;
        int height;
        int width;
        bool animated = false;
        int spriteNum;
        int offset;
        FlipState flip = FlipState::none;
        int animationDelayFrames;
        PositionComponent* position;
        SDL_Texture* objTexture;
        SDL_FRect srcRect, destRect;
};
