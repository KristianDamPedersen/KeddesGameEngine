#include "MapCollisionComponent.h"
MapCollisionComponent::MapCollisionComponent(SpriteComponent* sprite) {
    bbox = sprite->getDestRect();
}

void MapCollisionComponent::update() {
    std::cout << "MapCollisionComponent::update() called" << std::endl;
};

void MapCollisionComponent::draw(SDL_Renderer* renderer) {};

