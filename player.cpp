//
// Created by TANK1_41 on 1/25/2022.
//

#include "player.h"
#include "game.h"
player::player(SDL_Renderer *ren, int x, int y) {
    xpos = x;
    ypos = y;
    renderer = ren;
    playertex = textureManger::loadTexture("assets/player.png",ren);
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
    SDL_RenderCopy(renderer, playertex, &srcRect, &destRect);
}

