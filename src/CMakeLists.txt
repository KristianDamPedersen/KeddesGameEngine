add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)

add_subdirectory(game)

target_link_directories(${PROJECT_NAME} 
    PRIVATE external 
    PRIVATE game
)


target_link_libraries(${PROJECT_NAME} 
    PRIVATE external 
    PRIVATE game
)

