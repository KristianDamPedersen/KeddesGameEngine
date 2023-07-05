add_library(ecs
    ECS.h
    PositionComponent.h 
    PositionComponent.cpp
    SpriteComponent.h 
    SpriteComponent.cpp
    GravityComponent.h
    GravityComponent.cpp
)

target_link_libraries(ecs external)
