add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)

add_subdirectory(game)
add_subdirectory(textureManager)

target_link_directories(${PROJECT_NAME} 
    PRIVATE external 
    PRIVATE game
    PRIVATE textureManager
)


target_link_libraries(${PROJECT_NAME} 
    PRIVATE external 
    PRIVATE game
    PRIVATE textureManager
)

