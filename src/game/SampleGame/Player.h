#pragma once
#include "../ECS/ECS.h"
#include "SDL_render.h"
#include <memory>

class Player : public Entity {
    public:
        virtual void init() override;
        void updatePlayerPosition(const Uint8 *keystate);
};
