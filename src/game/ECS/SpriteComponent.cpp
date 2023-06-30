#include "SpriteComponent.h"
#include "../TextureManager.h"

/**
 * @brief Constructs a new SpriteComponent object.
 * 
 * This constructor initializes a new SpriteComponent object with the provided texture sheet, x and y coordinates.
 * 
 * @param textureSheet The path to the texture sheet file.
 * @param x The x-coordinate of the sprite.
 * @param y The y-coordinate of the sprite.
 * 
 * @throws std::runtime_error if the texture sheet fails to load.
 */
SpriteComponent::SpriteComponent(const char* textureSheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
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

    destRect.h = srcRect.h*2;
    destRect.w = srcRect.w*2;
    destRect.x = xpos;
    destRect.y = ypos;

}

void SpriteComponent::draw() {
    // This is where we render the updated game object.
    SDL_RenderTexture(Game::renderer, objTexture, &srcRect, &destRect);
}


