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
auto& player(manager.addEntity());
auto& enemy(manager.addEntity());

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
        player.addComponent<PositionComponent>();
        player.getComponent<PositionComponent>().setPos(200, 200);
        
        enemy.addComponent<PositionComponent>();
        enemy.getComponent<PositionComponent>().setPos(150, 150);
        
        
        // Fetch the player texture
        const char *file = "assets/knight.png"; // This is always relative to the binary's location
        int pX = player.getComponent<PositionComponent>().x();
        int pY = player.getComponent<PositionComponent>().y();

        player.addComponent<SpriteComponent>(file, pX, pY);

        int eX = enemy.getComponent<PositionComponent>().x();
        int eY = enemy.getComponent<PositionComponent>().y();
        enemy.addComponent<SpriteComponent>(file, eX, eY);

        

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
    std::cout << player.getComponent<PositionComponent>().x() << ", " << player.getComponent<PositionComponent>().y() << "\n";
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

