add_library(game
    Game.cpp
    Game.h
    TextureManager.h 
    TextureManager.cpp
    Map.h 
    Map.cpp
)

add_subdirectory(ECS)
add_subdirectory(SampleGame)

target_link_directories(game PRIVATE ECS PRIVATE SampleGame)
target_link_libraries(game external ecs sampleGame)
