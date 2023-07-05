#pragma once 
#include <vector>
#include <array>
#include "SDL.h"
#include "TextureManager.h"

class Map {
    public:
        Map(SDL_Renderer* renderer);
        ~Map();
        
        /* 
         * Function that loads a map from a 20x25 array of integers, which 
         * will be typecast to the valid tile types (TileType). WARNING: will crash
         * the program if invalid integers are passed in (or wrong dimensions)
         * @function LoadMapFromIntArray
         * @param arr 20x25 array of integers representing the map
         * @return void
         */
        void LoadMapFromIntArray(int arr[20][25]);
        void DrawMap();

        // TileTypes 
        enum class TileType {
            DIRT,
            GRASS,
            WATER,
            AIR
        };

        // Collisions 
        enum class CollisionDirection {
            NONE,
            TOP,
            BOTTOM,
            LEFT,
            RIGHT
        };

        std::vector<CollisionDirection> checkCollisionWithMap(SDL_FRect bbox);

    private:
        SDL_FRect srcRect, destRect;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;
        SDL_Texture* air;

        SDL_Renderer* gameRenderer;

        // Map is an array of TileTypes
        TileType map[20][25];
};
