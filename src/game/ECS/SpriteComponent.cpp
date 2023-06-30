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


void SpriteComponent::update() {
    // Here we update position etc.
    // xpos++; 
    // ypos++;
    
    srcRect.h = height; 
    srcRect.w = width;
    srcRect.x = 0;
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


