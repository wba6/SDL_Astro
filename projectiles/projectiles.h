//
// Created by William Aey on 2/3/2022.
//

#pragma once
#define SDL_ASTRO_PROJECTILES_H

#include <vector>
#include "../game-manager/game.h"


//TODO: implement collision
struct positionManager {
    int x, y;
};

class projectile {
public:
    projectile(const SDL_Rect &playerPos, double &angle, const int &mousePosX, const int &mousePosY);

    ~projectile();

    void update();

    void render();

    SDL_Rect *getDestRect();

private:

    double rectAngle;
    positionManager velocity;
    int xpos;
    int ypos;
    SDL_Rect srcRect, destRect;
};

class projectileManager {
public:
    void newProjectile(const SDL_Rect &playerPos, double &angle, const int &mousePosX, const int &mousePosY);

    std::vector<projectile *> projectiles;

    std::vector<projectile *> *getProjectiles();
};
