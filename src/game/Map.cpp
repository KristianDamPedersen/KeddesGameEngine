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

Map::Map(SDL_Renderer* renderer) {
    gameRenderer = renderer;
    air = TextureManager::LoadTexture("assets/air.png", gameRenderer);
    dirt = TextureManager::LoadTexture("assets/dirt.png", gameRenderer);
    grass = TextureManager::LoadTexture("assets/grass.png", gameRenderer);
    water = TextureManager::LoadTexture("assets/water.png", gameRenderer);
    
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
                    TextureManager::Draw(water, gameRenderer, srcRect, destRect);
                    break;
                
                case Map::TileType::GRASS:
                    TextureManager::Draw(grass, gameRenderer, srcRect, destRect);
                    break;
                
                case Map::TileType::DIRT:
                    TextureManager::Draw(dirt, gameRenderer, srcRect, destRect);
                    break;
                case Map::TileType::AIR:
                    TextureManager::Draw(air, gameRenderer, srcRect, destRect);
                    break;
           }
        }
    }
};


bool isCollidable(Map::TileType tileType) {
    switch (tileType) {
        case Map::TileType::AIR:
            return false;
        case Map::TileType::WATER:
            return false;
        case Map::TileType::GRASS:
            return true;
        case Map::TileType::DIRT:
            return true;
        default:
            return false;
    }
};

std::vector<Map::CollisionDirection> Map::checkCollisionWithMap(SDL_FRect bbox) {
    std::vector<Map::CollisionDirection> collisionDirections;

    std::cout <<"Checking collision with map" << std::endl;

    int bboxUpLeftX = bbox.x;
    int bboxUpLeftY = bbox.y;
    int bboxWidth = bbox.w;
    int bboxHeight = bbox.h;

    std::cout << "BBOX UL: " << bboxUpLeftX << ", " << bboxUpLeftY << std::endl;
    std::cout << "BBOX WIDTH: " << bboxWidth << std::endl;
    std::cout << "BBOX HEIGHT: " << bboxHeight << std::endl;
    
    return collisionDirections;
}

