add_library(game
    Game.cpp
    Game.h
    TextureManager.h 
    TextureManager.cpp
    GameObject.h
    GameObject.cpp
)

target_link_libraries(game external)
