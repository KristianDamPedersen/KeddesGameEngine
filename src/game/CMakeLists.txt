add_library(game
    Game.cpp
    Game.h
    TextureManager.h 
    TextureManager.cpp
    Map.h 
    Map.cpp
)

add_subdirectory(ECS)

target_link_directories(game PRIVATE ECS)
target_link_libraries(game external ecs)
