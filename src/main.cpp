#include "SDL.h"
#include "SDL_image.h"
#include "game/Game.cpp"

Game *game = nullptr;
int main() {
    SDL_Log("Hello World!");

    game = new Game();

    game->init("Game Window", 800, 600, false);

    while(game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}