#include "GravityComponent.h"
#include "PositionComponent.h"

GravityComponent::GravityComponent(PositionComponent* pos, int grav){
    gravity = grav;
    position = pos;
};

void GravityComponent::draw(SDL_Renderer* renderer) {};

void GravityComponent::update() {
    position->setPos(position->x(), position->y() + gravity);
};


