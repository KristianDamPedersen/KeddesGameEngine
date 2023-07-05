#include "Game.h"
#include "ECS/PositionComponent.h"
#include "ECS/MapCollisionComponent.h"
#include "ECS/GravityComponent.h"
#include "ECS/SpriteComponent.h"
#include "Map.h"
#include "SDL_keycode.h"
#include "SDL_render.h"
#include "GameObject.h"
#include "ECS/ECS.h"
#include <iostream>
#include <typeinfo>

// Create the player and the enemy
Game::Game() {
    manager = std::make_unique<Manager>();
    player = manager->addEntity();
}

Game::~Game() {}

SDL_Renderer *Game::renderer = nullptr;

void Game::init(const char* title, int width, int height, bool fullscreen) {
    // Check for fullscreen flag
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    // Initialize SDL, making sure it's successful
    std::cout << "Initializing game..." << std::endl;

    // Initialize timer
    bool success = true;
    if(SDL_Init(SDL_INIT_TIMER) < 0) {
        std::cout << "SDL init timer failed!" << std::endl;
        success = false;
    }

    // Initialize video
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL init video failed!" << std::endl;
        success = false;
    }

    // Initialize events
    if(SDL_Init(SDL_INIT_EVENTS) < 0) {
        std::cout << "SDL init events failed!" << std::endl;
        success = false;
    }


    if(success) {
        std::cout << "Subsystems initialized!..." << std::endl;

        // Create the window
        window = SDL_CreateWindow(title, width, height, flags);
        if(window) {
            std::cout << "Window created!" << std::endl;
        }

        // Create the renderer
        renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        
        map = std::make_unique<Map>(Game::renderer);
        
        // Add the position components
        // player.addComponent<PositionComponent>();
        // player.getComponent<PositionComponent>().setPos(0,0);
        player->addComponent(std::unique_ptr<Component>(new PositionComponent()));
        auto pos = player->getComponent<PositionComponent>();
        pos->setPos(0,0);
        
        


        // Add gravity component
        // player.addComponent<GravityComponent>(&player.getComponent<PositionComponent>(), 10);
        player->addComponent(std::unique_ptr<Component>(new GravityComponent(pos, 10)));
        
        
        // Add the dinosaur texture
        const char* playerFile = "assets/DinoSpritesVita.png";
        // player.addComponent<SpriteComponent>(playerFile, &player.getComponent<PositionComponent>(), 24, 24, 5);
        // player.getComponent<SpriteComponent>().setAnimation(3, 0, 100);
        player->addComponent(std::unique_ptr<Component>(new SpriteComponent(playerFile, Game::renderer, pos, 24, 24, 5)));

        // Add the map collision component
        // player.addComponent<MapCollisionComponent>(player.getComponent<SpriteComponent>());
        
        // Create the map
        // map = new Map();
        
        // Set isRunning to true
        isRunning = true;

    } else {
        // If SDL_Init fails, set isRunning to false
        std::cout << "SDL_Init failed!" << std::endl;
        SDL_Init(SDL_INIT_EVERYTHING);
        std::cout << SDL_GetError() << std::endl;
        isRunning = false;
    }
}

void updatePlayerPosition(const Uint8 *keystate, Entity& player) {
    auto pos = player.getComponent<PositionComponent>();
    auto sprite = player.getComponent<SpriteComponent>();
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

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    updatePlayerPosition(keystate, *player);
    
    switch(event.type) {
        // If the user clicks the X button, quit the game
        case SDL_EVENT_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    cnt++;
    manager->update();
    std::cout << "Player position: " << player->getComponent<PositionComponent>()->x() << ", " << player->getComponent<PositionComponent>()->y() << std::endl;
    std::cout << "Frame: " << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Render stuff here
    map->DrawMap();
    manager->draw(Game::renderer);
    
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    std::cout << "Game cleaned!" << std::endl;
}

bool Game::running() {
    return isRunning;
}

