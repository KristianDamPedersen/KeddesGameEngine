#include "Game.h"
#include "SDL_render.h"
#include <iostream>

// SDL_Texture* playerTex;
// SDL_Rect srcR, destR;


Game::Game() {}

Game::~Game() {}

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
        
        // Fetch the player texture
        const char *file = "assets/knight.png"; // This is always relative to the binary's location
        SDL_Surface* tmpSurface = IMG_Load(file);
        if(!tmpSurface) {
            std::cout << "Failed to load image!" << std::endl;
        }

        playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
        std::cout << SDL_GetError() << std::endl;
        SDL_DestroySurface(tmpSurface);
        
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
    destR.h = 64;
    destR.w = 64;
    destR.x = cnt;
    destR.y = cnt;
    std::cout << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Render stuff here
    SDL_RenderTexture(renderer, playerTex, NULL, &destR);
    std::cout << SDL_GetError() << std::endl;

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

