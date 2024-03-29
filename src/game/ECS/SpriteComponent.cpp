#include "SpriteComponent.h"
#include "../TextureManager.h"
#include "PositionComponent.h"
#include "SDL_render.h"

SpriteComponent::SpriteComponent(const char* textureSheet, SDL_Renderer* renderer, PositionComponent* posComp, int h, int w, int s) {
    objTexture = TextureManager::LoadTexture(textureSheet, renderer);
    position = posComp;
    height = h;
    width = w;
    scale = s;
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

void SpriteComponent::draw(SDL_Renderer* renderer) {
    // This is where we render the updated game object.
    switch (flip) {
        case FlipState::none:
            SDL_RenderTexture(renderer, objTexture, &srcRect, &destRect);
            break;
        case FlipState::horizontal:
            SDL_RenderTextureRotated(renderer, objTexture, &srcRect, &destRect, 0, nullptr, SDL_FLIP_HORIZONTAL);
            break;
        case FlipState::vertical:
            SDL_RenderTextureRotated(renderer, objTexture, &srcRect, &destRect, 0, nullptr, SDL_FLIP_VERTICAL);
            break;
    }
}

SpriteComponent::FlipState SpriteComponent::getFlipState(){
    return flip;
}

void SpriteComponent::setFlipState(FlipState flipState){
    flip = flipState;
}

SDL_FRect SpriteComponent::getSrcRect() {
    return srcRect;
}

SDL_FRect SpriteComponent::getDestRect() {
    return destRect;
}
