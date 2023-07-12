add_library(ecs
    ECS.h
    PositionComponent.h 
    PositionComponent.cpp
    SpriteComponent.h 
    SpriteComponent.cpp
    GravityComponent.h
    GravityComponent.cpp
    EntityType.h
    EnumClassIterator.h
)

target_link_libraries(ecs external)
