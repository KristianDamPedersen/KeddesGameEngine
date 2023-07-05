#pragma once 
#include "ECS.h" 
#include "SDL.h"
#include "PositionComponent.h"

class GravityComponent : public Component {
    
    public: 
        GravityComponent(PositionComponent* pos, int gravity);
        virtual void update() override;
        virtual void draw(SDL_Renderer* renderer) override;
    
    private: 
        PositionComponent* position;
        int gravity;
};
