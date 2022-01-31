cmake_minimum_required(VERSION 3.21)
project(SDL_Astro)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/assets)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/x64)

add_executable(SDL_Astro main.cpp game.cpp game.h textureManager.cpp textureManager.h player.cpp player.h enemy.cpp enemy.h)

target_link_libraries(${PROJECT_NAME}
        SDL2main
        SDL2
        SDL2_image
        zlib1
        libpng16-16
        libjpeg-9)
