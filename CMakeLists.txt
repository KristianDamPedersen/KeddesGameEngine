cmake_minimum_required(VERSION 3.26.4)

project(KEG)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external)
add_subdirectory(src)

# Copy assets to build folder.
file(COPY src/assets DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/src")
