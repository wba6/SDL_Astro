cmake_minimum_required(VERSION 3.21)
project(SDL_Astro)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/x64)

add_executable(
  SDL_Astro
  game-manager/main.cpp
  game-manager/game.cpp
  game-manager/textureManager.cpp
  player/player.cpp
  enemy/enemy.cpp
  projectiles/projectiles.cpp
  game-manager/Check_collision.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  SDL2main
  SDL2
  SDL2_image
)
