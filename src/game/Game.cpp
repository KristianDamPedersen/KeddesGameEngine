#include "Game.h"
#include "ECS/PositionComponent.h"
#include "ECS/SpriteComponent.h"
#include "Map.h"
#include "SDL_render.h"
#include "GameObject.h"
#include "ECS/ECS.h"
#include <iostream>

// Create the map
Map* map;

// Create component manager 
Manager manager;

// Create the player and the enemy
// auto& is type inference! 
auto& duox(manager.addEntity());
auto& tard(manager.addEntity());
auto& mort(manager.addEntity());

Game::Game() {}

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
        
        // Add the position components
        tard.addComponent<PositionComponent>();
        tard.getComponent<PositionComponent>().setPos(0, 0);
        
        duox.addComponent<PositionComponent>();
        duox.getComponent<PositionComponent>().setPos(100, 100);

        mort.addComponent<PositionComponent>();
        mort.getComponent<PositionComponent>().setPos(200, 200);
        
        
        // Add the dinosaur texture
        const char *duoxFile = "assets/DinoSpritesDuox.png";
        duox.addComponent<SpriteComponent>(duoxFile, &duox.getComponent<PositionComponent>(), 24, 24, 5);
        duox.getComponent<SpriteComponent>().setAnimation(3, 0, 100);

        const char* tardFile = "assets/DinoSpritesTard.png";
        tard.addComponent<SpriteComponent>(tardFile, &tard.getComponent<PositionComponent>(), 24, 24, 5);
        tard.getComponent<SpriteComponent>().setAnimation(6, 4, 100);

        const char* mortFile = "assets/DinoSpritesMort.png";
        mort.addComponent<SpriteComponent>(mortFile, &mort.getComponent<PositionComponent>(), 24, 24, 5);
        mort.getComponent<SpriteComponent>().setAnimation(4, 13, 100);
        
        

        
        

        

        // Create the map
        map = new Map();
        
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

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
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
    manager.update();
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Render stuff here
    map->DrawMap();
    manager.draw();
    
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

