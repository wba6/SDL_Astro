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
    //TODO:create an instance of astroid class with random starting position


    /*double randomXSpawn = (rand() % 900);
    double randomYSpawn = 0;
    //get random cord and give it a random chance of being negative
    randomXSpawn = (rand() % 10) < 5 ? randomXSpawn * -1 : randomXSpawn;*/

//    if(randomXSpawn > 0)
//    {
//        randomYSpawn = (windowWidth / 2.f) + std::sqrt(pow(windowHight, 2) - pow((randomXSpawn - (windowHight)),2));
//    }else{
//        //makes it possible to have a negative y cord if x is neg
//        randomYSpawn = (windowWidth / 2.f) - std::sqrt(pow(windowHight, 2) - pow(((randomXSpawn*-1.f) - (windowHight)), 2));
//        randomYSpawn *= -1.f;
//    }
//    std::cout<< "random x spawn: "<<randomXSpawn<<" Random y spawn: "<<randomYSpawn;
//    double slopeY = windowHight / 2.f - randomYSpawn/2.f;
//    double slopeX = windowWidth / 2.f - randomXSpawn/2.f;
    astroids *astroid = new astroids(50, 50);
    movementSlope.push_back({astroid, 50, 50});
    std::cout << "astoid created" << std::endl;
}

void astroidManager::update() {
    double y = 50, x = 50;
    movementSlope.at(0).instance->render(x, y);
}

void astroidManager::render() {

}

astroids::astroids(int x, int y) {
    xpos = x;
    ypos = y;
    astroidTex = textureManger::loadTexture("assets/astroid.png");
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 64;
    srcRect.h = 64;
    destRect.w = 64;
    destRect.h = 64;
}

astroids::~astroids() {

}

void astroids::render(double &moveY, double &moveX) {
//    double nextY = -1 * ((moveY/moveX) * ((destRect.x - 4.f) - destRect.x)) + destRect.y;
//    destRect.x+=4.f;
//    destRect.y = nextY - destRect.y;

    std::cout << " ||| dest x spawn: " << destRect.x << " dest y spawn: " << destRect.y << std::endl;
    SDL_RenderCopy(Game::renderer, astroidTex, &srcRect, &destRect);
}
