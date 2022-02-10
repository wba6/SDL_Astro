//
// Created by TANK1_41 on 1/25/2022.
//

#include "Astro/game.h"

astroidManager *astMan;
player *playerOne;
Game::Game() : textures(this), Manageprojectiles(this) {}

Game::~Game() { delete playerOne; }

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
  int flags{0};
  // checks if fullscreen is true
  flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
  // checks to make sure that the system is initialized correctly before making
  // a window
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "subsystem running" << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    // check if window was made successfully
    if (window) {
      std::cout << "window created" << std::endl;
    }

    // create render
    renderer = SDL_CreateRenderer(window, -1, flags);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
      std::cout << "Render created" << std::endl;
    }

    isRunning = true;
  } else {
    isRunning = false;
  }
  playerOne = new player(this, 50, 50);
  astMan = new astroidManager(this, window);
  astMan->createAstroid();
}

void Game::handleEvents() {
  // gets events
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;
  }
}

void Game::update() {
  playerOne->update();
  astMan->createAstroid();
  astMan->update();
  Manageprojectiles.update();
  collision::checkCollision(astMan->getMovementSlope(), playerOne);
  collision::checkCollision(astMan->getMovementSlope(),
                            Manageprojectiles.getProjectiles());
}

void Game::addProjectile(projectile *p) {
    std::cout<<"add projectile"<<std::endl;
  Manageprojectiles.projectiles.push_back(p);
}

void Game::render() {
  // clear render buffer
  SDL_RenderClear(renderer);
  // render texture
  Manageprojectiles.RenderProjectiles();
  astMan->render();
  playerOne->render();
  // render new stuff
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << "game cleaned" << std::endl;
}

bool Game::running() { return isRunning; }

SDL_Window *Game::getWindow() const {
    return window;
}

