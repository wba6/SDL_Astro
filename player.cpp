//
// Created by TANK1_41 on 1/25/2022.
//

#include "player.h"
#include "game.h"
player::player(int x, int y) {
    xpos = x;
    ypos = y;
    playertex = textureManger::loadTexture("assets/player.png");
}

player::~player() {

}

void player::update() {
    xpos++;
    ypos++;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 32;
    srcRect.h = 32;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 64;
    destRect.h = 64;
}

void player::render() {
    SDL_RenderCopy(Game::renderer, playertex, &srcRect, &destRect);
}

