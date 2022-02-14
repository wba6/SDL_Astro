#include "Astro/game.h"
#include <ctime>

int main() {
    // limit the frame rate
    const int fps = 120;
    const int frameDelay = 1000 / fps;
    Uint32 frameStart;
    int frameTime;
    srand(time(NULL));

    Game *game = nullptr;
    game = new Game();
    game->init("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
               false);

    while (game->running()) {
        // amount of ticks from when sdl was init
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        // gets amount of time it takes to run through program
        frameTime = SDL_GetTicks() - frameStart;
        // if it ran through program faster than frame delay it will slow down the
        // program to the frameDelay or 60 fps
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    delete game;
    return 0;
}
