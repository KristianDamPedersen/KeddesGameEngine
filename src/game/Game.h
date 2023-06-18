#include "SDL.h"

class Game {
    public:
        Game();
        ~Game();

        /*
            * Initialize the game window
            * @param title The title of the window
            * @param xpos The x position of the window
            * @param ypos The y position of the window
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

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};