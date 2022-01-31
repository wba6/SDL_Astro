//
// Created by William Aey on 1/31/2022.
//

#pragma once
#define SDL_ASTRO_ENEMY_H

#include <vector>
#include "game.h"

struct astroidMovment {
    double instance, xSlope, ySlope;
};

class astroidManager {
public:
    astroidManager();

    ~astroidManager();

    void createAstroid();

    void update();

    void render();

private:

    std::vector<astroidMovment> movementSlope;
};

class astroids : public astroidManager {

};