#pragma once
#include "ECS.h"

class PositionComponent : public Component {
    private:
        int xpos;
        int ypos;
    
    public:
        PositionComponent();
        // Getters for current x and y position
        int x();
        int y();

        // Sets position equal to the provided parameters
        void setPos(int x, int y);

        // Increments x and y with 1
        virtual void update() override;
};
