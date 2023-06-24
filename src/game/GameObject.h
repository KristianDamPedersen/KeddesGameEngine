#include "SDL.h"
class GameObject {
    public: 
        GameObject(const char* textureSheet, SDL_Renderer*, int x, int y);
        ~GameObject();

        void Update();

        void Render();

    private: 
        int xpos;
        int ypos;
        SDL_Texture* objTexture;
        SDL_FRect srcRect, destRect;
        SDL_Renderer* renderer;
};
