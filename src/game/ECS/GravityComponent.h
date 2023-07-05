#pragma once 
#include "ECS.h" 
#include "SDL.h"
#include "PositionComponent.h"

class GravityComponent : public Component {
    
    public: 
        GravityComponent(PositionComponent* pos, int gravity);
        void init() override;
        void update() override;
        void draw() override;
    
    private: 
        PositionComponent* position;
        int gravity;
};
