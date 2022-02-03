//
// Created by William Aey on 2/3/2022.
//

#include "projectiles.h"

projectile::projectile(const SDL_Rect &playerPos, double &angle, const int &mousePosX, const int &mousePosY) {
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 64;
    srcRect.h = 64;
    destRect.y = playerPos.y;
    destRect.x = playerPos.x;

    rectAngle = angle;
    velocity.y = (mousePosY - playerPos.y);
    velocity.x = (mousePosX - playerPos.x);
}

projectile::~projectile() {

}

void projectile::update() {
    destRect.x += velocity.x;
    destRect.y += velocity.y;
    this->render();
}

void projectile::render() {
    std::cout << "projectile rendered at " << destRect.x << " " << destRect.y << std::endl;
    SDL_RenderDrawRect(Game::renderer, &destRect);
}


void
projectileManager::newProjectile(const SDL_Rect &playerPos, double &angle, const int &mousePosX, const int &mousePosY) {
    projectile *newProject = new projectile(playerPos, angle, mousePosX, mousePosY);
    projectiles.push_back(newProject);
}
