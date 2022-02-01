//
// Created by William Aey on 1/31/2022.
//

#pragma once
#define SDL_ASTRO_ENEMY_H

#include <vector>
#include "game.h"

class astroids {
public:

    astroids(int x, int y);

    virtual ~astroids();

    void render(double &moveY, double &moveX);

private:
    int xpos;
    int ypos;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Texture *astroidTex;
};

struct astroidMovment {
    astroids *instance;
    double slopeX, slopeY;
};

class astroidManager {
public:
    astroidManager(SDL_Window *window);

    ~astroidManager();

    void createAstroid();

    void update();

    void render();

private:
    int windowWidth;
    int windowHight;
    std::vector<astroidMovment> movementSlope;
};

