#include "SpriteComponent.h"
#include "../TextureManager.h"

SpriteComponent::SpriteComponent(const char* textureSheet, int x, int y, int s) {
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
    scale = s;
}

void SpriteComponent::init() {
}


void SpriteComponent::update() {
    // Here we update position etc.
    xpos++; 
    ypos++;
    
    srcRect.h = 64; 
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = srcRect.h*scale;
    destRect.w = srcRect.w*scale;
    destRect.x = xpos;
    destRect.y = ypos;

}

void SpriteComponent::draw() {
    // This is where we render the updated game object.
    SDL_RenderTexture(Game::renderer, objTexture, &srcRect, &destRect);
}


