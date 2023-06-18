# add_library(game)


# target_sources(game
#     PRIVATE
#         Game.cpp
#     PUBLIC
#         ${CMAKE_CURRENT_LIST_DIR}/Game.h
# )
add_library(game
    Game.cpp
    Game.h
)

target_link_libraries(game external)