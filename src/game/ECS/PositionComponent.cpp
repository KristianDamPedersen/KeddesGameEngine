#include "PositionComponent.h"


int PositionComponent::x() {
    return xpos;
};

int PositionComponent::y() {
    return ypos;
};

void PositionComponent::setPos(int x, int y) {
    xpos = x;
    ypos = y;
}

void PositionComponent::init() {
    xpos = 0;
    ypos = 0;
};

void PositionComponent::update() {
    xpos++;
    ypos++;
};
