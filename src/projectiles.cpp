//
// Created by William Aey on 2/3/2022.
//

#include "Astro/projectiles.h"
#include "Astro/game.h"

projectile::projectile(Game *game, const SDL_Rect &playerPos, double &angle,
                       const int &mousePosX, const int &mousePosY)
    : game(game) {
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 64;
    srcRect.h = 64;
    destRect.w = 8;
    destRect.h = 16;
    destRect.x = destRect.y = 64;

    destRect.y = playerPos.y;
    destRect.x = playerPos.x;

    rectAngle = angle;
    velocity.y = (mousePosY - playerPos.y) / 20;
    velocity.x = (mousePosX - playerPos.x) / 20;
}

projectile::~projectile() {}

void projectile::update() {
    destRect.x += velocity.x;
    destRect.y += velocity.y;
}

void projectile::render() {
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(game->renderer, &destRect);
    SDL_SetRenderDrawColor(game->renderer, 200, 0, 0, 255);
}

SDL_Rect *projectile::getDestRect() { return &destRect; }

projectileManager::projectileManager(Game *game) : game(game) {}

void projectileManager::newProjectile(const SDL_Rect &playerPos, double &angle,
                                      const int &mousePosX,
                                      const int &mousePosY) {
    projectile *newProject =
            new projectile(game, playerPos, angle, mousePosX, mousePosY);
    projectiles.push_back(newProject);
}

std::vector<projectile *> *projectileManager::getProjectiles() {
    return &projectiles;
}

void projectileManager::RenderProjectiles() {
    for (auto inst: projectiles) {
        inst->render();
    }
}

void projectileManager::update() {
    for (auto inst: projectiles) {
        inst->update();
    }
    /*
     * deletes out of range projectiles
     * */
    for (int i = 0; i < projectiles.size(); ++i) {
        int x, y{0};
        SDL_GetWindowSize(game->getWindow(), &x, &y);
        for (int i = 0; i < projectiles.size(); ++i) {
            SDL_Rect *location = projectiles.at(i)->getDestRect();
            if (location->x > x + 1000 || location->x < x - 1000) {
                projectiles.erase(projectiles.begin() + i);
                i--;
            } else if (location->y > y + 1000 || location->y < y - 1000) {
                projectiles.erase(projectiles.begin() + i);
                i--;
            }
        }
    }
}
