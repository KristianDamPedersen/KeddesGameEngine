#include "SpriteComponent.h"
#include "../TextureManager.h"
#include "PositionComponent.h"

SpriteComponent::SpriteComponent(const char* textureSheet, PositionComponent* posComp, int h, int w, int s) {
    objTexture = TextureManager::LoadTexture(textureSheet);
    position = posComp;
    height = h;
    width = w;
    scale = s;
}

void SpriteComponent::init() {
}

void SpriteComponent::setAnimation(int numSprites, int spriteOffset, int delayFrames) {
    animated = true;
    spriteNum = numSprites;
    offset = spriteOffset;
    animationDelayFrames = delayFrames;
}


void SpriteComponent::update() {
    if (animated) {
        srcRect.x = (offset * width) + srcRect.w * static_cast<int>((SDL_GetTicks() / animationDelayFrames) % spriteNum);
    } else {
        srcRect.x = 0;
    }
    srcRect.h = height; 
    srcRect.w = width;
    srcRect.y = 0;

    destRect.h = srcRect.h*scale;
    destRect.w = srcRect.w*scale;
    destRect.x = position->x();
    destRect.y = position->y();

}

void SpriteComponent::draw() {
    // This is where we render the updated game object.
    SDL_RenderTexture(Game::renderer, objTexture, &srcRect, &destRect);
}


