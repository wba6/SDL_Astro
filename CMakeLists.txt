cmake_minimum_required(VERSION 3.21)
project(SDL_Astro)

set(CMAKE_CXX_STANDARD 14)


include_directories(${PROJECT_SOURCE_DIR}/include)
if (WIN32)
    link_directories(${PROJECT_SOURCE_DIR}/lib/x64)
endif ()
add_executable(
        SDL_Astro
        src/main.cpp
        src/game.cpp
        src/textureManager.cpp
        src/player.cpp
        src/enemy.cpp
        src/projectiles.cpp
        src/Check_collision.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  SDL2main
  SDL2
  SDL2_image
)
