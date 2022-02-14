//
// Created by TANK1_41 on 1/25/2022.
//

#include "Astro/game.h"

Game::Game() : textures(this), score(0), lost(false), Manageprojectiles(this) {}

Game::~Game() {
    delete playerOne;
    delete astMan;
    delete scoreMan;
    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
}

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
    int flags{0};
    // checks if fullscreen is true
    flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
    // checks to make sure that the system is initialized correctly before making
    // a window
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "subsystem running" << std::endl;
        TTF_Init();
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        // check if window was made successfully
        if (window) {
            std::cout << "window created" << std::endl;
        }

        // create render
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
    scoreMan = new scoreManager(this);
}

void Game::handleEvents() {
    // gets events
    events.clear();
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
        }
        events.push_back(event);
    }
}

void Game::update() {
    if (!lost) {
        playerOne->update();
        astMan->createAstroid();
        astMan->update();
        Manageprojectiles.update();
        if (collision::checkCollision(astMan->getMovementSlope(), playerOne)) {
            loseCondition(true);
        }
        score += collision::checkCollision(astMan->getMovementSlope(),
                                           Manageprojectiles.getProjectiles());
    } else {
        restart();
    }
    scoreMan->upadateScore(score);
}

void Game::addProjectile(projectile *p) {
    Manageprojectiles.projectiles.push_back(p);
}

void Game::render() {
    // clear render buffer
    SDL_RenderClear(renderer);
    // render texture
    scoreMan->render();
    Manageprojectiles.RenderProjectiles();
    astMan->render();
    playerOne->render();
    // render new stuff
    SDL_RenderPresent(renderer);
}

bool Game::running() { return isRunning; }

SDL_Window *Game::getWindow() const {
    return window;
}

void Game::loseCondition(bool winLoss) {
    lost = winLoss;
}

void Game::restart() {
    int numKeys;
    const Uint8 *keys = SDL_GetKeyboardState(&numKeys);
    if (keys[SDL_SCANCODE_R]) {
        astMan->getMovementSlope()->clear();
        Manageprojectiles.projectiles.clear();
        loseCondition(false);
        score = 0;
    }
}
