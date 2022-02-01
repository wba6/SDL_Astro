//
// Created by William Aey on 1/31/2022.
//

#include <valarray>
#include "enemy.h"


astroidManager::astroidManager(SDL_Window *window) {
    SDL_GetWindowSize(window, &windowWidth, &windowHight);
}

astroidManager::~astroidManager() {

}

void astroidManager::createAstroid() {
    //TODO:Impliment collision
    static int frameCounter = 200;
    if (frameCounter >= 200) {
        double randomXSpawn = (rand() % 900);
        double randomYSpawn = 0;
        //get random cord and give it a random chance of being negative
        randomXSpawn = (rand() % 10) < 5 ? randomXSpawn * -1 : randomXSpawn;

        if (randomXSpawn > 0) {
            randomYSpawn =
                    (windowWidth / 2.f) + std::sqrt(pow(windowHight, 2) - pow((randomXSpawn - (windowHight)), 2));
        } else {
            //makes it possible to have a negative y cord if x is neg
            randomYSpawn = (windowWidth / 2.f) -
                           std::sqrt(pow(windowHight, 2) - pow(((randomXSpawn * -1.f) - (windowHight)), 2));
            randomYSpawn *= -1.f;
        }
        double slopeY = windowHight / 2.f - randomYSpawn / 2.f;
        double slopeX = windowWidth / 2.f - randomXSpawn / 2.f;
        double slope = slopeY / slopeX;
        auto *ast = new astroids(randomXSpawn, randomYSpawn);
        movementSlope.push_back({ast, slope});
        std::cout << "astroid created" << std::endl;
        frameCounter = 0;
    } else {
        frameCounter++;
    }
}

void astroidManager::update() {
    for (auto as: movementSlope) {
        as.instance->update(as.slope);
    }
}

void astroidManager::render() {
    for (auto as: movementSlope) {
        as.instance->render();
    }
}

std::vector<astroidMovment> *astroidManager::getMovementSlope() {
    std::vector<astroidMovment> *movementTemp = &movementSlope;
    return movementTemp;
}

astroids::astroids(int x, int y) {
    astroidTex = textureManger::loadTexture("assets/astroid.png");
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = 64;
    srcRect.h = destRect.h = 64;
    destRect.x = x;
    destRect.y = y;
}

astroids::~astroids() {

}

void astroids::update(const double &slope) {
    double nextY = -1 * (slope * ((destRect.x - 4.f) - destRect.x)) + destRect.y;
    destRect.x += 4.f;
    double movementAmountY = nextY - destRect.y;
    destRect.y += movementAmountY;
}

void astroids::render() {
    std::cout << " ||| dest x spawn: " << destRect.x << " dest y spawn: " << destRect.y << std::endl;
    SDL_RenderCopy(Game::renderer, astroidTex, &srcRect, &destRect);
}

SDL_Rect *astroids::getDestRect() {
    SDL_Rect *temp = &destRect;
    return temp;
}

