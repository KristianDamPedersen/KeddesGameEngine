#include "Map.h" 
#include <array>
#include <iostream>


// Function that takes an integer and casts it to a TileType
Map::TileType intToTileType(int i) {
    switch(i) {
        case 0:
            return Map::TileType::AIR;
        case 1:
            return Map::TileType::DIRT;
        case 2:
            return Map::TileType::GRASS;
        case 3:
            return Map::TileType::WATER;
        default:
            // Crash the program if invalid integers are passed in
            std::cout << "Invalid integer passed into intToTileType! (HINT: check the integer array)" << std::endl;
            exit(1);
    }
}

int lvl1[20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

Map::Map() {
    dirt = TextureManager::LoadTexture("assets/dirt.png");
    grass = TextureManager::LoadTexture("assets/grass.png");
    water = TextureManager::LoadTexture("assets/water.png");
    
    // Initialize map with default level
    LoadMapFromIntArray(lvl1);

    // Initalize srcRect and destRect
    srcRect.w = 32;
    srcRect.h = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.w = 32;
    destRect.h = 32;
    destRect.x = 0;
    destRect.y = 0;
};

Map::~Map(){};

void Map::LoadMapFromIntArray(int newMap[20][25]) {
    
    for (int row = 0; row < 20; row++) {
        
        for (int column = 0; column < 25; column++) {
            map[row][column] = intToTileType(newMap[row][column]);
        }
    }
};

void Map::DrawMap() {
    
    for (int row = 0; row < 20; row++) {
        
        for (int column = 0; column < 25; column++) {
            
            TileType type = map[row][column];
            
            destRect.x = column * 32;
            
            destRect.y = row * 32;
            
            switch (type) {
                case Map::TileType::WATER:
                    TextureManager::Draw(water, srcRect, destRect);
                    break;
                
                case Map::TileType::GRASS:
                    TextureManager::Draw(grass, srcRect, destRect);
                    break;
                
                case Map::TileType::DIRT:
                    TextureManager::Draw(dirt, srcRect, destRect);
                    break;
           }
        }
    }
};
