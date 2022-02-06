//
// Created by William Aey on 2/3/2022.
//

#include "projectiles.h"

projectile::projectile(const SDL_Rect &playerPos, double &angle, const int &mousePosX, const int &mousePosY) {
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

projectile::~projectile() {

}

void projectile::update() {
    destRect.x += velocity.x;
    destRect.y += velocity.y;
}

void projectile::render() {
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(Game::renderer, &destRect);
    SDL_SetRenderDrawColor(Game::renderer, 200, 0, 0, 255);
}

SDL_Rect *projectile::getDestRect() {
    return &destRect;
}


void
projectileManager::newProjectile(const SDL_Rect &playerPos, double &angle, const int &mousePosX, const int &mousePosY) {
    projectile *newProject = new projectile(playerPos, angle, mousePosX, mousePosY);
    projectiles.push_back(newProject);

}

std::vector<projectile *> *projectileManager::getProjectiles() {
    return &projectiles;
}
