#pragma once 
#include "Game.h" 

class Map {
    
    public:
        Map();
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
            WATER
        };

    private:
        SDL_FRect srcRect, destRect;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

        // Map is an array of TileTypes
        TileType map[20][25];
};
