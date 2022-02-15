//
// Created by William Aey on 1/31/2022.
//

#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <valarray>
#include <vector>

class Game;

enum direction {
    forward,
    backwords
};

class astroids final {
    Game *game;

public:
    astroids(Game *game, int x, int y);

    void update(const double &slope, const direction &direct);

    void render();

    SDL_Rect *getDestRect();

private:
    SDL_Rect srcRect, destRect;
    SDL_Texture *astroidTex;
};

struct astroidMovment {
    astroids *instance;
    double slope;
    direction direct;

    astroidMovment(astroids *instance, double slope, direction direct);
    astroidMovment(const astroidMovment &) = delete;
    astroidMovment(astroidMovment &&other) noexcept;
    astroidMovment &operator=(astroidMovment &&other) noexcept;
    ~astroidMovment();
};

class astroidManager {
    Game *game;

public:
    astroidManager(Game *game, SDL_Window *window);

    void createAstroid();

    void update();

    void render();

    std::vector<astroidMovment> *getMovementSlope();

private:
    int windowWidth;
    int windowHight;
    std::vector<astroidMovment> movementSlope;
};
