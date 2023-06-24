#include "SDL.h"
#include "SDL_image.h"
#include "SDL_stdinc.h"
#include "game/Game.cpp"

Game *game = nullptr;
int main() {

    // Meta variables
    const int FPS = 60;
    const int frameDelay = 1000 / FPS; 
    Uint32 frameStart; 
    int frameTime;


    game = new Game();

    game->init("Game Window", 800, 640, false);

    while(game->running()) {
        
        // Get the time at which we start the frame
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();
        
        // Calculate the time it took us to execute the frame
        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        };
    }

    game->clean();

    return 0;
}
