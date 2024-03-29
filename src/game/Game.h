#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Map.h"
#include "ECS/ECS.h"
#include "TextureManager.h"

class Game {
    public:
        Game();
        ~Game();

        /*
            * Initialize the game window
            * @param title The title of the window
            * @param width The width of the window
            * @param height The height of the window
            * @param fullscreen Whether or not the window should be fullscreen
        */
        void init(const char* title, int width, int height, bool fullscreen);

        void handleEvents();

        void update();

        void render();

        void clean();

        bool running();

        static SDL_Renderer *renderer;

private:
    int cnt = 0;
    bool isRunning;
    // std::vector<std::shared_ptr<Entity>> entities;
    std::unique_ptr<Manager> manager;
    std::unique_ptr<Map> map;
    // std::shared_ptr<Entity> player;
    SDL_Window *window;
    SDL_FRect srcRect, destRect; 
};
