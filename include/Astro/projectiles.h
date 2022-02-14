//
// Created by William Aey on 2/3/2022.
//

#pragma once

#include <SDL2/SDL_rect.h>
#include <vector>

//TODO: delete projectiles when they go out of bounds
struct positionManager {
    int x, y;
};

class Game;

class projectile {
    Game *game;

public:
    projectile(Game *game, const SDL_Rect &playerPos, double &angle,
               const int &mousePosX, const int &mousePosY);

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
    Game *game;

public:
    explicit projectileManager(Game *game);

    std::vector<projectile *> projectiles;

    void newProjectile(const SDL_Rect &playerPos, double &angle,
                       const int &mousePosX, const int &mousePosY);

    void RenderProjectiles();

    void update();

    std::vector<projectile *> *getProjectiles();
};
