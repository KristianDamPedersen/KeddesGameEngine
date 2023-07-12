#include "Player.h"
#include <iostream>
#include "SDL_keycode.h"
#include "../ECS/EntityType.h"
#include "../ECS/PositionComponent.h"
#include "../ECS/SpriteComponent.h"
#include "../ECS/GravityComponent.h"

void Player::init() {
    addComponent(std::make_unique<PositionComponent>());
    auto pos = getComponent<PositionComponent>();
    pos->setPos(0,0);
    
    // Add the gravity component to the player, with strength 20
    addComponent(std::make_unique<GravityComponent>(pos, 20));
    
    // Add the spritesheet to the player
    // const char* playerSprite = "../assets/DinoSpriteTard.png";
    // addComponent(std::make_unique<SpriteComponent>(
    //             playerSprite,
    //             getRenderer(),
    //             pos,
    //             24,
    //             24,
    //             5
    //             ));
};

void Player::updatePlayerPosition(const Uint8 *keystate) {
    auto pos = getComponent<PositionComponent>();
    auto sprite = getComponent<SpriteComponent>();
    if (keystate[SDL_SCANCODE_UP] && !(keystate[SDL_SCANCODE_DOWN])) {
        std::cout << "up" << std::endl;
        pos->setPos(
            pos->x(),
            pos->y()-5
        );
        sprite->setAnimation(6, 4, 100);
    }
    else if (!keystate[SDL_SCANCODE_UP] && keystate[SDL_SCANCODE_DOWN]){
        std::cout << "down" << std::endl;
        pos->setPos(
            pos->x(),
            pos->y()+5
        );
        sprite->setAnimation(6, 4, 100);
    }
    if (keystate[SDL_SCANCODE_RIGHT] && !keystate[SDL_SCANCODE_LEFT]){
        std::cout << "right" << std::endl;
        pos->setPos(
            pos->x()+5,
            pos->y()
        );
        sprite->setAnimation(6, 4, 100);
        sprite->setFlipState(SpriteComponent::FlipState::none);
    }
    else if (!keystate[SDL_SCANCODE_RIGHT] && keystate[SDL_SCANCODE_LEFT]){
        std::cout << "left" << std::endl;
        pos->setPos(
            pos->x()-5,
            pos->y()
        );
        sprite->setAnimation(6, 4, 100);
        sprite->setFlipState(SpriteComponent::FlipState::horizontal);
    } else if (!keystate[SDL_SCANCODE_UP] && !keystate[SDL_SCANCODE_DOWN] && !keystate[SDL_SCANCODE_RIGHT] && !keystate[SDL_SCANCODE_LEFT]){
        sprite->setAnimation(3, 0, 100);
    }
};
