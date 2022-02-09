//
// Created by TANK1_41 on 1/25/2022.
//

#include "game.h"
#include "../player/player.h"
#include "../enemy/enemy.h"
#include "Check_collision.h"

astroidManager *astMan;
player *playerOne;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;
Game::Game() {

}

Game::~Game() {
    delete playerOne;
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags{0};
    //checks if fullscreen is true
    flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
    //checks to make sure that the system is initialized correctly before making a window
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "subsystem running" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        //check if window was made successfully
        if (window) {
            std::cout << "window created" << std::endl;
        }

        //create render
        renderer = SDL_CreateRenderer(window, -1, flags);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
            std::cout << "Render created" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }
    playerOne = new player(50, 50);
    astMan = new astroidManager(window);
    astMan->createAstroid();

}

void Game::handleEvents() {
    //gets events
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
        }
    }
}

void Game::update() {
    playerOne->update();
    astMan->createAstroid();
    astMan->update();
    collision::checkCollision(astMan->getMovementSlope(), playerOne);
}

void Game::render() {
    //clear render buffer
    SDL_RenderClear(renderer);
    //render texture
    astMan->render();
    playerOne->render();
    //render new stuff
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << "game cleaned" << std::endl;
}

bool Game::running() {
    return isRunning;
}
