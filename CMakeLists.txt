cmake_minimum_required(VERSION 3.21)
project(SDL_Astro)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/assets)
if(WIN32)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/x64)
endif()

#if(unix)

add_executable(SDL_Astro game-manager/main.cpp game-manager/game.cpp game-manager/game.h game-manager/textureManager.cpp game-manager/textureManager.h player/player.cpp player/player.h enemy/enemy.cpp enemy/enemy.h game-manager/Check_collision.cpp game-manager/Check_collision.h
        projectiles/projectiles.cpp projectiles/projectiles.h)

target_link_libraries(${PROJECT_NAME}
        SDL2main
        SDL2
        SDL2_image
        )
