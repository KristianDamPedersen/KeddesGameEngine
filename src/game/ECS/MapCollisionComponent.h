#pragma once 
#include "ECS.h" 
#include "SDL.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "../Map.h"

class MapCollisionComponent : public Component {
    
    public: 
        MapCollisionComponent(SpriteComponent* sprite);
        virtual void update() override;
        virtual void draw(SDL_Renderer* renderer) override;
    
    private: 
        std::vector<Map::CollisionDirection> collisionDirections;
        SDL_FRect bbox;
};
