#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
}

void GameObject::Update() {
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

void GameObject::Render() {
    // This is where we render the updated game object.
    SDL_RenderTexture(Game::renderer, objTexture, &srcRect, &destRect);
}


