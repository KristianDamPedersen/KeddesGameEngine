#pragma once
#include "ECS.h"

class PositionComponent : public Component {
    private:
        int xpos;
        int ypos;
    
    public:
        // Getters for current x and y position
        int x();
        int y();

        // Sets position equal to the provided parameters
        void setPos(int x, int y);
        
        // Initializes the component with position (0,0)
        void init() override;

        // Increments x and y with 1
        void update() override;
};
